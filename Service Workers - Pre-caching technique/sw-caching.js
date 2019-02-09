const cacheName = 'v1';
const assets = [
    'index.html',
    'main.js',
    'style.css',
    'img/icon.png'
];

self.addEventListener('install', e => // onde ocorre o pré-caching dos recursos
{
    e.waitUntil(
        caches.open(cacheName).then(cache => cache.addAll(assets))
    );

    return self.skipWait();
});

self.addEventListener('fetch', e => 
{
    e.respondWith(
       // caches.match(e.request).then(res => res || fetch(e.request)) // retorna o que estiver na cache ou caso não exista, ignora a cache
        caches.match(e.request).then(res => 
        {
            if(res) return res;

            let requestToCache = e.request.clone(); // precisa de clonar a requesição, pois ela só pode ser usada uma vez

            return fetch(requestToCache).then(res =>
            {
                if(!res || res.status !== 200) return res; // caso haja algum erro, ele retorna o erro
                
                let responseToCache = res.clone(); // busca a requisição clonada, retorna uma resposta e caso não tenha erros, ela clona ela 

                caches.open(cacheName).then(cache => cache.put(requestToCache, responseToCache)) // coloca na cache, trabalha com os clones

                return res; // retorna a resposta que tinha sido clonada
            });
            
        })
    );
});
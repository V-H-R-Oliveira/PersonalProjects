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
});

self.addEventListener('fetch', e => 
{
    e.respondWith(
        caches.match(e.request).then(res => res || fetch(e.request)) // retorna o que estiver na cache ou caso não exista, ignora a cache
    );
});
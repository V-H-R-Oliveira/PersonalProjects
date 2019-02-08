if('serviceWorker' in navigator)
{
    window.addEventListener('load', () =>
    {
        navigator.serviceWorker.register('sw-caching.js').then(reg => console.log(reg.scope)).catch(err => console.error(err));
    })
}

window.addEventListener('load', () =>
{
    fetch('https://jsonplaceholder.typicode.com/posts').then(res => res.json()).then(data => 
    {
        let output = "";
        data.forEach(post => 
        {
            output += `
                <div class="post">
                    <h2>${post.title}</h2>
                    <article>
                        ${post.body}
                    </article>
                </div> 
            `
        });
        document.getElementById('output').innerHTML = output;
    }).catch(err => console.error(err));
});
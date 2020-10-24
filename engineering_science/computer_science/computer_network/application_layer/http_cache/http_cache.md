# HTTP Cache



##### # Cache Validate

Two steps for cache validate:

1. **Freshness check.** Some HTTP responses contain `Expires` header, which set a absolute expiration date of the page. The caching server first checks whether an historical response is not expired for now. If it is, cache hits.

2. **Revalidate**. Even the cache has expired already, it is still possible that the server has not changed the content of that page for now, hence a revalidation is executed, which is called a **conditional GET**. A `if-modified-since` header is added into the HTTP request header and sent to server, if not, a **304 Not Modified** response without content will be given by the server, otherwise the response will be the normal **200 OK** with modified contents.

    Specially, a `Cache-control: must-revalidate` header can be set by the client that forces the caching server to revalidate the cache.


# Cloud Computing

S3 & Dynamo

Aurora

BigQuery

Delta Lake



Amazon S3 EC2 (2006)

Google BigQuery (2011)

AWS Redshift (2012)

AWS Aurora Lambda (2014)



Public Cloud: the provider is another company, private cloud: internal PaaS/IaaS system (VMware).





Differences in building cloud software



How do these factors affect data systems?

- Much larger scale.
- Multitenancy.
- Elasticity.
- Updatability.



### 2. S3, Dynamo: Object Stores

Goal: Store some bytes reliably and cheaply for a long time period. The primary goal is scale: keep the interface very simple to support trillions of object.

Mostly target immutable or rarely changing data, so consistency is not as important.

Interface: key-value stores

- Object have a key
- Values can be up to a few TB in size
- Can only do operations on 1 key atomically

Consistency: eventual consistency, that is, different readers may see different versions of the same object.

S3 API:

- PUT(key, value): 
- GET(key, [range]): 
- LIST([startKey]): 





### Google BigQuery





### Delta Lake














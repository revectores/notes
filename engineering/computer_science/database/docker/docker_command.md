# Docker Commands

Notes: Since container name is required to be unique `[container_name]` and `[container_id]` are interchangeable.

| Functions                                        | Commands                                                     |
| ------------------------------------------------ | ------------------------------------------------------------ |
| login to registry                                | `docker login [server]`                                      |
| pull image from registry                         | `docker pull [image_name]`                                   |
| build image based on `Dockerfile`                | `docker build -f [Dockerfile]`                               |
| list leave images                                | `docker image ls` / `docker images`                          |
| list all images (includes intermediate images)   | `docker image ls -a`                                         |
| run docker container, configure the port mapping | `docker container run --name [container_name] -p [physical_port:container_port] [image_name]` |
| list running docker containers                   | `docker container ls` / `docker ps`                          |
| list all docker containers                       | `docker container ls -a`                                     |
| get low-level information about container        | `docker container inspect [container_name]`                  |
| run command inside container                     | `docker container exec [container_name] [command]`           |
| enter container shell                            | `docker container exec -it [container_name] /bin/bash`       |
| pause container                                  | `docker pause [container_name]`                              |
| stop docker container (send `SIGTERM`)           | `docker container stop [container_name]`                     |
| kill docker container (send `SIGKILL`)           | `docker container kill [container_name]`                     |
| remove docker container                          | `docker container rm [container_name]`                       |
| remove docker image                              | `docker image rm [repository]:[tag]`                         |



### 1. Container Management

The container management commands are grouped under `docker container`.

To list the all running containers, use

```shell
docker container ls
```

The historical equivalence is `docker ps`. To list containers in all status, add `-a` option.











### 2. Container Image Management

The container image management commands are grouped under `docker image`.




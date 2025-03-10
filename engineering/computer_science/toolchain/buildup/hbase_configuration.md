# HBase Configuration Steps

**Step1**. Configure Hadoop. Refer to [hadoop_configuration_steps.md](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/distributed_computing/Hadoop/hadoop_configuration_steps.md) for this purpose. 

**Step2**. Download HBase

```shell
> wget https://mirrors.tuna.tsinghua.edu.cn/apache/hbase/2.3.3/hbase-2.3.3-bin.tar.gz
```

Decompress:

```shell
> sudo tar xzf hbase-2.3.3.tar.gz
> mv hbase-2.3.3 hbase
> cd hbase
```

Configure `JAVA_HOME` env:

```{.sh .numberLines startFrom="28" filename="hbase/conf/hbase-env.sh"}
export JAVA_HOME=$(readlink -f /usr/bin/java | sed "s:bin/java::")
```

Check it works:

```shell
> ./bin/hbase
```



**Step3**. HBase Pseudo Distributed Nodes

Some extra env configuration:

```{.sh .numberLines startFrom="30" filename="hbase/conf/hbase-env.sh"}
# Extra Java CLASSPATH elements.  Optional.
export HBASE_CLASSPATH=/opt/hadoop/conf
```

```{.sh .numberLines startFrom="125" filename="hbase/conf/hbase-env.sh"}
# Tell HBase whether it should manage it's own instance of ZooKeeper or not.
export HBASE_MANAGES_ZK=true
```



```{.xml .numberLines startFrom="22" filename="hbase/conf/hbase-site.xml"}
<configuration>
    <property>
    	<name>hbase.rootdir</name>
        <value>hdfs://localhost:9000/hbase</value>
    </property>
    <property>
    	<name>hbase.cluster.distributed</name>
        <value>true</value>
    </property>
</configuration>
```












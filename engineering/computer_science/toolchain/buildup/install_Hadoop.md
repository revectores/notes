# Hadoop Configuration Steps

**Step1**. Install Java

```shell
> yum install java-1.8.0-openjdk
> yum install -y java-1.8.0-openjdk-devel
```

Test whether Java and jps is successfully installed:

```shell
> java -version
> jps
```



**Step2**. Create a Hadoop user and configure the ssh public/private key pairs.

Create the user `hadoop` and add it in sudo list:

```shell
> sudo useradd -m hadoop -s /bin/bash
> sudo passwd hadoop
> usermod -aG wheel hadoop
```

Configure the ssh key pair:

```shell
> mkdir .ssh
> ssh-keygen -t rsa
> cat ./id_rsa.pub >> ./authorized_keys
> chmod 600 authorized_keys
> cd ..
> chmod 700 .ssh
```

Now test whether you can ssh to localhost without password:

```shell
> ssh localhost
> exit
```

in case you make something wrong and you want to delete the user:

```shell
> sudo userdel -rf hadoop
```



**Step3**. Install Hadoop

Download from Apache or mirror:

```shell
> sudo wget https://mirrors.tuna.tsinghua.edu.cn/apache/hadoop/common/hadoop-3.3.0/hadoop-3.3.0.tar.gz
> sudo wget https://downloads.apache.org/hadoop/common/hadoop-3.3.0/hadoop-3.3.0.tar.gz
```

Decompress:

```shell
> sudo tar xzf hadoop-3.3.0.tar.gz
> mv hadoop-3.3.0 hadoop
> cd hadoop
```

Configure `JAVA_HOME` env:

```shell
> vi etc/hadoop/hadoop-env.sh
```

```{.c .numberLines startFrom="54" filename="hadoop/etc/hadoop/hadoop-env.sh"}
export JAVA_HOME=$(readlink -f /usr/bin/java | sed "s:bin/java::")
```

Now run Hadoop bin to test:

```shell
> ./bin/hadoop
```



**Step4**. Hadoop Pseudo Distributed Nodes

Configure `core-site.xml`:

```{.xml .numberLines startFrom="19" filename="hadoop/etc/hadoop/core-site.xml"}
<configuration>
    <property>
        <name>hadoop.tmp.dir</name>
        <value>file:/opt/hadoop/tmp</value>
        <description>Abase for other temporary directories</description>
    </property>
    <property>
        <name>fs.defaultFS</name>
        <value>hdfs://localhost:9000</value>
    </property>
</configuration>
```

Configure `hdfs-site.xml`:

```{.xml .numberLines startFrom="19" filename="hadoop/etc/hadoop/hdfs-site.xml"}
<configuration>
    <property>
        <name>dfs.replication</name>
        <value>1</value>
    </property>
    <property>
       	<name>dfs.namenode.name.dir</name>
		<value>file:/opt/hadoop/tmp/dfs/name</value>
    </property>
    <property>
    	<name>dfs.datanode.data.dir</name>
        <value>file:/opt/hadoop/tmp/dfs/data</value>
    </property>
</configuration>
```

Format namenode:

```shell
> ./bin/hdfs namenode -format
```

Start Hadoop:

```shell
> ./sbin/start-dfs.sh
```

Check whether the Hadoop service has been started:

```shell
> jps
21600 DataNode
21490 NameNode
22770 Jps
21812 SecondaryNameNode
```

to terminate the Hadoop service:

```shell
> ./sbin/stop-dfs.sh
```




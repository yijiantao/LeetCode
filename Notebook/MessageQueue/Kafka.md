&emsp;&emsp;Kafka属于分布式的消息引擎系统，它的主要功能是提供一套完备的消息发布与订阅解决方案。
在Kafka中，发布订阅的对象是主题（Topic），你可以为每一个业务，每个应用甚至是每类数据都创建专属的主题。


# Kafka体系结构
&emsp;&emsp;**Kafka的服务端：** 由被称为Broker的服务进程构成，即一个Kafka集群由多个Broker组成，Broker负责接收和处理客户端发送过来的请求，以及对消息进行持久化。
<br>
&emsp;&emsp;Kafka的客户端：
<br>
&emsp;&emsp;**Kafka的高可用：** 对数据进行备份，即把相同的数据拷贝在不同的多台机器上。Kafka定义了两类副本：领导者副本（Leader Replica）和追随者副本（Follower Replica）。领导者副本（Leader Replica）可以对外提供服务，这里的对外服务指的是与客户端程序进行交互；而追随者副本（Follower Replica）只是被动的追随领导者副本而已，不能与外界进行交互。（P.s.类似于MySQL的主从库，但是从库也是可以处理读请求的）。

## Kafka的三层消息架构：
- 第一层是主题层：每个主题可以配置M个分区，而每个分区又可以配置N个副本；
- 第二层是分区层：；
- 第三层是消息层：；

# Kafka版本

# 生产环境中Kafka集群部署方案

# 最重要的集群参数
## 如何配置Broker端参数

## 如何配置Topic、JVM和操作系统参数


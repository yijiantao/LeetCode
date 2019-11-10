# 2019年第45周 2019.11.04 - 2019.11.08

&emsp;&emsp;写写总结吧，，，自觉写周报即视感，，，

## Algorithm

&emsp;&emsp;刷刷水题，话说python都没有指针这种东东，这道题目做起来怪怪的，于是用go现学现卖吧= =

[Leetcode 21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

## Review

[高并发系统：它的通用设计方法是什么？](https://time.geekbang.org/column/article/137323)  
<br>
&emsp;&emsp;最近阅读了有关高并发系统设计的相关姿势，总结一下：应对高并发大流量时也会采用类似“抵御洪水”的方案，归纳起来共有三种方法。
- **Scale-out（横向扩展）：** 分流/分而治之是一种常见的高并发系统设计方法，采用分布式部署的方式把流量分流开，让每个服务器都承担一部分并发和流量。
- **缓存：** 使用缓存来提高系统的性能，就好比用“拓宽河道/水库”的方式抵抗高并发大流量的冲击。
- **异步：** 在某些场景下，未处理完成之前，我们可以让请求先返回，在数据准备好之后再通知请求方，这样可以在单位时间内处理更多的请求。

&emsp;&emsp;备注："Scale-up(纵向扩展)"，通过购买性能更好的硬件来提升系统的并发处理能力，比方说目前系统 4 核 4G 每秒可以处理 200 次请求，那么如果要处理 400 次请求呢？很简单，我们把机器的硬件提升到 8 核 8G（硬件资源的提升可能不是线性的，这里仅为参考）。  
&emsp;&emsp;而"Scale-out"，则是另外一个思路，它通过将多个低性能的机器组成一个分布式集群来共同抵御高并发流量的冲击。沿用刚刚的例子，我们可以使用两台 4 核 4G 的机器来处理那 400 次请求。


## Tip

&emsp;&emsp;关于 django+celery+redis环境配置：celery是python开发的分布式任务调度模块，celery本身不含消息服务，它使用第三方消息服务来传递任务，目前，celery支持的消息服务有RabbitMQ，redis甚至是数据库，redis是最佳选择。  
&emsp;&emsp;如下配置流程默认环境中已安装配置好python3.x，已成功安装django。

```bash
# 在 Ubuntu 安装celery
pip3 install celery
pip3 install django-celery

# 在 Ubuntu 安装redis
pip3 install redis
pip3 install celery-with-redis

# django的项目目录下的setting.py中添加配置信息
INSTALLED_APPS中添加内容:
INSTALLED_APPS = [
    ......
    'djcelery',   
]

# 添加配置信息：
import djcelery
djcelery.setup_loader() # 加载djcelery

# 数据库调度
CELERYBEAT_SCHEDULER='djcelery.schedulers.DatabaseScheduler'
BROKER_URL='redis://127.0.0.1:6379/0'
BROKER_TRANSPORT='redis'

```

&emsp;&emsp;不过这种异步的多任务框架，要审视自己的系统是否真的需要，martin fowler好像曾经说过，能使用单体解决的问题，就不要采用分布式。不能为了技术而技术，采用分布式固然可以分流用户请求，提高系统的响应能力，但同样也带来了复杂性。开发服务或者系统最终的目的是商业利益。如果单体跑的很好，或者通过scale up方式在成本可控的情况能解决就不要想着诗和远方，因为系统内部的进程间调用，肯定比不同物理机的进程之间调用要快。

## Share

[知乎专栏 Redis为什么用跳表而不用平衡树？](https://zhuanlan.zhihu.com/p/23370124)

最近在琢磨着用 django+celery+redis的方式拆分异步任务，用 redis 做消息队列，同时又在学习跳表等数据结构，结合实际场景，通过了解redis内部实现的数据结构，进而加深对跳表等数据结构的理解。
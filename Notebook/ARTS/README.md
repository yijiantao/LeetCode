# 2019年第45周 2019.11.04 - 2019.11.08

&emsp;&emsp;写写总结吧，，，自觉写周报即视感，，，

## Algorithm

&emsp;&emsp;刷刷水题，话说python都没有指针这种东东，这道题目做起来怪怪的，于是用go现学现卖吧= =

[Leetcode 21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

## Review

> 待补充。。。

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

## Share

[知乎专栏 Redis为什么用跳表而不用平衡树？](https://zhuanlan.zhihu.com/p/23370124)

最近在琢磨着用 django+celery+redis的方式拆分异步任务，用 redis 做消息队列，同时又在学习跳表等数据结构，结合实际场景，通过了解redis内部实现的数据结构，进而加深对跳表等数据结构的理解。
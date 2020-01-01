# Django中的设计模式

## MVT模式
&emsp;&emsp;Django的MTV模式本质上和MVC是一样的，也是为了各自组建保持一个松耦合关系，只是定义上有些许的不同，Django的MTV分别是：
- M 代表模型（model）：负责业务对象和数据库的关系映射（ORM）
- T 代表模板（Templates） : 负责如何把页面展示给用户（HTML）
- V 代表试图（View） ：负责业务逻辑，并在适当的时候调用Model和Template

除了以上三层之外，还需要一个URL分离器，他的作用是将一个个URL的页面请求分发给不同的View处理，View在调用相应的Model和Template

>1、Web服务器（中间件）收到一个http请求<br>
2、Django在URLconf里查找相对应的试图（View）函数来处理http请求<br>
3、试图函数调用相应的数据模型来存取数据、调用相应的模板展示页面<br>
4、试图函数处理结束后返回一个http的响应给Web服务器<br>
5、Web服务器将响应发送给客户端<br>

这种设计模式关键的优势在于各种组件都是的松耦合的，这样的话，每个由Django驱动的Web应用都有着明确的目的，并且可以独立更改而不影响到其他的部分

比如，开发者更改一个应用程序中的URL，而不用影响这个程序底层的实现，设计师可以改变HTML页面的样式而不用接触Python代码

数据管理员可以重新命名数据库，并且只需要更改模型，无需从一大堆文件中查找和替换


## 观察者模式
&emsp;&emsp;观察者模式（有时又被称为发布（publish）-订阅（Subscribe）模式、模型-视图（View）模式、源-收听者(Listener)模式或从属者模式）是软件设计模式的一种。在此种模式中，一个目标物件管理所有相依于它的观察者物件，并且在它本身的状态改变时主动发出通知。这通常透过呼叫各观察者所提供的方法来实现。此种模式通常被用来实现事件处理系统。

Django中，存在Singal与dispatch类，分别用来发送和接受信号，实现被观察与观察者的角色。

首先，我们可以定义一个观察者，接收一种特定的信号：


## Django RestframWork中的REST设计
&emsp;&emsp;在Django Restframework框架中的APIView类中，提供了put(), delete(), patch()方法的支持。
&emsp;&emsp;比如，如果你想上传一个文件，对应的view就可以这样写：
```
class FileUploadView(views.APIView):
    parser_classes = (FileUploadParser,) 

    def put(self, request, filename, format=None): 
        file_obj = request.data['file'] 
        # ... 
        # do some stuff with uploaded file 
        # ... 
        return Response(status=204)
```

&emsp;&emsp;如果你想再服务器端发送请求，Django Restframework中APIClient类提供了各种方法，get(), post(), put(), patch(), delete(), head() and options()。
```
from rest_framework.test import APIClient

client = APIClient()
client.post('/notes/', {'title': 'new idea'}, format='json')
```
&emsp;&emsp;总的来说，Django提供的框架使得代码量减少了很多，使得程序员只需关注核心的业务逻辑。
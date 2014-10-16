#/bin/bash
curl https://api.spark.io/v1/devices/abcd/move -d access_token=1234 -d args=movefwd,90
curl https://api.spark.io/v1/devices/abcd/move -d access_token=1234 -d args=moveup,120
curl https://api.spark.io/v1/devices/abcd/move -d access_token=1234 -d args=claw,0
curl https://api.spark.io/v1/devices/abcd/move -d access_token=1234 -d args=claw,40
curl https://api.spark.io/v1/devices/abcd/move -d access_token=1234 -d args=rotate,0
curl https://api.spark.io/v1/devices/abcd/move -d access_token=1234 -d args=movefwd,130
curl https://api.spark.io/v1/devices/abcd/move -d access_token=1234 -d args=claw,0
curl https://api.spark.io/v1/devices/abcd/move -d access_token=1234 -d args=moveup,90
curl https://api.spark.io/v1/devices/abcd/move -d access_token=1234 -d args=rotate,90

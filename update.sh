#给出一个默认的项目路径
path="/Users/rxy/Desktop/RXY-s-NoteBook"

#先进入项目当中

cd $path

echo "####### 进入自己的项目 #######"

ls

echo "开始执行命令"

git add .

git status

#写个sleep 1s 是为了解决并发导致卡壳

sleep 1s

echo "####### 添加文件 #######"

ls_date=`date +%Y%m%d`

git commit -m "${ls_date}"

echo "####### commit #######"

sleep 1s

echo "####### 开始推送 #######"

git push origin main

if [ $? -ne 0 ]; then
    echo "####### 推送失败 #######"
    exit 1
fi

else
    echo "####### 推送成功 #######"
fi

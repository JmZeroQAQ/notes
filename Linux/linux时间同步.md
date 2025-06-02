### Linux 时间同步

**systemd-timesyncd:**

`systemd-timesyncd` 是一个 `SNTP` 客户端，用于跨网络同步系统时钟。

使用:

```shell
timedatectl set-ntp true
```

查看服务状态:

```shell
timedatectl status
```

如果看见 `NTP service: active` 就说明服务启动成功了

配置:

systemd-timesyncd 启动时会读取 `/etc/systemd/timesyncd.conf` 配置文件，该文件的配置默认是全部注释的，内容如下:

```conf
[Time]
#NTP=
#FallbackNTP=0.arch.pool.ntp.org 1.arch.pool.ntp.org 2.arch.pool.ntp.org 3.arch.pool.ntp.org
#RootDistanceMaxSec=5
#PollIntervalMinSec=32
#PollIntervalMaxSec=2048
#ConnectionRetrySec=30
#SaveIntervalSec=60
```

如果不增加或者更改时间同步服务器，`systemd-timesyncd` 是不需要我们配置的，他有一个默认的 `FallbackNTPServers`，如果没有配置NTP服务器，他会在这里读取NTP服务器列表。
使用 `timedatectl show-timesync --all` 查看 `FallbackNTPServers` 列表

如果要修改默认配置，取消:

```conf
#NTP=
#FallbackNTP=0.arch.pool.ntp.org 1.arch.pool.ntp.org 2.arch.pool.ntp.org 3.arch.pool.ntp.org
```

这两行的注释，进行配置即可。

参考: [Arch Wiki](https://wiki.archlinuxcn.org/wiki/Systemd-timesyncd)

获取更多信息:
`man 5 timesyncd.conf`
`man 8 systemd-timesyncd.service`

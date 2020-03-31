## 0th Task

-   [ ] Get [docker](#docker-install) installed and running :arrow_left: This is my recomendation if you're not familiar with programming or are using windows.
-   [ ] Get [python](#required-python-packages) and packages installed :arrow_left: If you're alreay familiar with python and have it on your computer
-   [ ] Get ROOT built/installed :arrow_left: If you're already familiar with ROOT is and are doing research in nuclear or high energy physics




### Docker install

For windows computers I would suggest using docker. If installing for windows choose the linux images option not the windows images option.

-   Install for [Windows 10](https://docs.docker.com/docker-for-windows)
-   Install for [Windows 7](https://docs.docker.com/toolbox/toolbox_install_windows)
-   Install for [MacOS](https://docs.docker.com/docker-for-mac/install)

Docker is essentially a lightweight virtual machine called images. I have one of these images availbe with ROOT and python already installed in it for you.

First check that docker it working on your machine by running the hello-world image. In a terminal or command prompt window run this.

```bash
docker run --rm -it hello-world
```

If that doesn't work, email me and I'll try to help you get started.

If that works, great you're one more step to programming! Now run this command.

I know this works on macOS/Linux I don't know on windows yet.
```bash
docker run --rm -it -e USER="user" -p 9999:9999 -v $PWD:/home/user/data -w /home/user/data --entrypoint "jupyter" uofscphysics/root:v6_18_02 notebook --allow-root --ip=0.0.0.0 --port=9999;
```

If you have macOS/Linux add this to your rc file to get make a useful function.

```bash
jupyter-root () {
	docker run --rm -it \
        -e USER="user" -e DISPLAY=$DISPLAY \
        -e QT_X11_NO_MITSHM="1" \
        -p 9999:9999 \
        -v $PWD:/home/user/data \
        -v $HOME/.Xauthority:/home/user/.Xauthority \
        -w /home/user/data \
        -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
        --entrypoint "jupyter" uofscphysics/root:v6_18_02 notebook --allow-root --ip=0.0.0.0 --port=9999;
}
```


### Required Python Packages

First make sure you have python3.5 or newer. If not just use [docker](#docker-install).

```bash
python --version
```

To install the python packages make sure you have pip that it's using python3. 

```bash
pip3 --version
```

```bash
pip3 install jupyter matplotlib numpy scipy pandas
```
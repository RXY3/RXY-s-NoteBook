# Mkdocs使用教程
如何使用mkdocs进行笔记记录 + 生成静态网站并部署到GitHub Pages
本教程基于本地环境进行部署，较为简单，不涉及CI/CD等高级操作。
本教程配置环境为MacOS，Linux环境配置类似，Windows环境请自行查找相关教程。

## 1. 预先准备
- 安装Python
> Mkdocs是基于Python的，所以需要安装Python
```bash
# 安装Python
brew install python
# 查看Python版本
python --version
```
- 安装pip
> pip是Python的包管理工具，用于安装Python包
```bash
# 安装pip
brew install pip
# 查看pip版本
pip --version
```
- 安装Mkdocs
```bash
# 安装Mkdocs
pip install mkdocs
# 查看Mkdocs版本
mkdocs --version
# 插件安装
pip install mkdocs-material
```

## 2. 初始化项目
- 初始化项目
在github上新建一个仓库，然后clone到本地
```bash
# git clone
git clone address_of_your_repository
# 进入仓库
cd your_repository
```
- 初始化mkdocs
```bash
# 初始化mkdocs
mkdocs new .
```
- 修改配置文件
使用vscode进行修改
```bash
code  .
```
修改mkdocs.yml文件
```yaml
site_name: your_site_name
theme:
  name: material
nav:
    - Home: index.md
    - Python: Python/Python基础.md
    - AI: AI/机器学习/机器学习基础.md
    - C: CorCpp/C/C基础.md
    - C++: CorCpp/C++/C++基础.md
    - Bash: Missing_sem/Bash.md
    - git: Missing_sem/git.md
    - Markdown: Missing_sem/Markdown.md
    - ZJU_CS: ZJU_CS
```
具体设置可参考本项目的mkdocs.yml文件
- 修改index.md文件
通过vscode修改index.md文件，添加首页内容
```markdown
# Welcome to xxx's Note
Hello, this is xxx's note. Here you can find some notes about programming, and other things. Enjoy!  
```
修改其他文件方式相同

## 3. 本地预览
```bash
# 本地预览
mkdocs serve
```
在浏览器中输入localhost:8000查看效果

## 4. 部署到GitHub Pages
方法一：手动部署
```bash
# 生成静态网站
mkdocs build
# 进入site文件夹
cd site
# 初始化git
git init
# 添加远程仓库
git remote add origin address_of_your_repository
# 添加所有文件
git add .
# 提交
git commit -m "first commit"
# 推送
git push -u origin master
```
在GitHub仓库的Settings中找到GitHub Pages，将source设置为master branch，然后保存，稍等片刻，就可以在GitHub Pages中看到你的网站了

方法二：使用mkdocs gh-deploy
```bash
# 生成静态网站并部署
mkdocs gh-deploy
```
稍等片刻，就可以在GitHub Pages中看到你的网站了

方法三：进行文件配置部署
在文件夹中新建.github/workflows文件夹，然后新建一个yml文件，文件名自定义，内容如下
```yaml
name: ci 
on:
  push:
    branches:
      - master 
      - main
permissions:
  contents: write
jobs:
  deploy:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - uses: actions/setup-python@v4
        with:
          python-version: 3.x
      - uses: actions/cache@v2
        with:
          key: ${{ github.ref }}
          path: .cache
      - run: pip install mkdocs-material
      - run: pip install pillow cairosvg
      - run: mkdocs gh-deploy --force
```
然后将文件push到GitHub仓库，在项目中的settings中找到Pages，将source设置为gh-pages branch，然后保存，稍等片刻，就可以在GitHub Pages中看到你的网站了
进入项目的Actions中，可以看到部署的过程，并找到部署的网址，形如https://xxx.github.io/your_repository

每次修改后，只需要push到GitHub仓库，GitHub Actions会自动部署，无需手动操作

针对于push操作也可以使用sh文件进行自动化操作，具体操作可参考本项目的.sh文件

## 5. 其他
在进行mkdoc serve时  

当你在mkdocs.yml中添加了nav: social: 时，出现如下错误
```bash
Required dependencies of "social" plugin not found.
```
这是因为缺少依赖，导致无法加载插件。
解决方法：  
```bash
pip install "mkdocs-material[imaging]"
brew install cairo freetype libffi libjpeg libpng zlib
brew install pngquant
```

## 6. 参考
- [Mkdocs官方文档](https://www.mkdocs.org/)
- https://www.youtube.com/watch?v=Q-YA_dA8C20&t=659s


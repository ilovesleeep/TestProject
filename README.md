# TestProject

## Set user info
	$ git config --global user.name "xxx"
	$ git config --global user.email "xxx@xxx"

	$ ssh-keygen -t rsa -C "xxx@xxx"        // 一路 Enter

	$ cat ~/.ssh/id_rsa.pub			// 复制公钥

在 Github 上点击个人头像，Settings -> SSH and GPG keys -> New SSH key

Title 随便写，将公钥粘贴到 Key 中，点击 Add SSH key 确认

	// 测试
	$ ssh -T git@github.com

键入 yes，出现 successfully 内容即可

## Fork and Clone
	// 在 Github 上 Fork 本项目，然后将 Fork 的项目 Clone 到本地
	$ git clone git@github.com:xxx/TestProject.git

	// 写代码 ...

	// 提交代码变化到缓存区（-A 选项：包括修改、添加和删除）
	$ git add -A

	// 将缓存区内容提交到当前本地分支，并附上提交说明 "xxx"
	$ git commit -m "xxx"

	// 将代码提交到远程 main 分支
	$ git push origin main

## Pull requests

...

===========================================================================

i added the origin main (42 repository) and the my github repository so when i can push to multiple repository at the same instead of creating different directory 

first we check the what are the current remote repos

```bash
git remote --verbose ## verbose means give extra information
```

we should get something like this 

```bash
origin  git@vogsphere.42.fr:intra-uuid/push_swap.git (fetch)
origin  git@vogsphere.42.fr:intra-uuid/push_swap.git (push)
```

now what to do to add a second repo
go to github and get the ssh 

```bash
git remote add github git@github.com:YOUR_USERNAME/push_swap.git ## place your ssh here 

git remote -v
```

yous hould see something like this 

```bash
origin   git@vogsphere.42.fr:... (fetch)
origin   git@vogsphere.42.fr:... (push)
github   git@github.com:... (fetch)
github   git@github.com:... (push)
```

what to do now when we work 

```bash 
git add .
git commit -m "commit"
## to 42 
git push origin main ## origin the name of the remote repo an the main is the branch 

## to github
git push github master:main ## master is the local branch and the main is remote branch 
```

#### Trick

-  we can add alias so when can push to both in the same time 
```bash
git config --global alias.pushall '!git push origin main && git push github main'

git pushall

## to check all the alias you have 
git config --get-regexp alias
```

- make you github repo the default 
```bash
git push -u github main

git push
```


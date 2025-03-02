default:
    @echo "Bitch"

ben:
	git commit --amend --author="benoeckl <ben@oeckl.com>" --no-edit --no-gpg-sign
	git rebase --continue 
max:
	git commit --amend --author="MaxRodler <maximilianreinerrodler@gmail.com>" --no-edit --no-gpg-sign
	git rebase --continue

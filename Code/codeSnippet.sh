#! /bin/bash/

read -p "0：get from local; 1: sync to local;" op

dir=~/Library/Developer/Xcode/UserData/CodeSnippets

snippet_from_local() {
	if [[ ! -d ./CodeSnippets ]]; then
		mkdir ./CodeSnippets
	fi

	if [[ -d ${dir} ]]; then
		cp ${dir}/*.codesnippet ./CodeSnippets/
	fi
}

snippet_to_local() {
	cp ./CodeSnippets/*.codesnippet ${dir}/
}

if [[ ${op} -eq 0 ]]; then
	snippet_from_local
elif [[ ${op} -eq 1 ]]; then
	snippet_to_local
fi

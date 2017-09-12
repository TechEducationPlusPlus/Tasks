declare -x id=0
declare -x contest=0
for i in `seq 1 7` ; 
do 
	declare -x dirTests="`ls -d 0$i*`"
	declare -x dirDescriptions="`ls -d $i*`"
	echo $dirTests $dirDescriptions;
	cat "$dirTests/README.md" | cut -d'|' -f2 | tail -n +3 | head -n -1 > "$dirTests/tasks.txt";
	declare -x ind=0
	declare -x tasks=""
	while IFS= read -r var
	do
	  var=`echo "$var" | xargs`
	  echo "$ind -> $var"
	  ind=$(($ind + 1));
	  id=$(($id + 1));
	  if [[ $ind -lt 10 ]] ;
	  then
		desc="`ls $dirDescriptions/0$ind*`";
	  else
		desc="`ls $dirDescriptions/$ind*`";
	  fi
	  pattern="`ls "$dirTests/$var/"*.in.* | sed ':a;N;$!ba;s/\n/,/g' | sed "s/$dirTests\\/$var\\///g" | sed 's/.in.txt//g'`";
	  url1=`echo "$desc" | sed -f escape.sed`
	  url2=`echo "$dirTests/$var/" | sed -f escape.sed`
	  echo "($id, '$var', 'https://github.com/TechEducationPlusPlus/Tasks/tree/master/Programming%20Basics/$url1', 'https://raw.githubusercontent.com/TechEducationPlusPlus/Tasks/master/Programming%20Basics/$url2', '*.in.txt', '*.out.txt', 'diff', '$pattern', '100', '0.1s', '256M'),";
	  echo "($id, '$var', 'https://github.com/TechEducationPlusPlus/Tasks/tree/master/Programming%20Basics/$url1', 'https://raw.githubusercontent.com/TechEducationPlusPlus/Tasks/master/Programming%20Basics/$url2', '*.in.txt', '*.out.txt', 'diff', '$pattern', '100', '0.1s', '256M')," >> tasks;
	  if [[ "$tasks" = "" ]];
	  then
		  tasks="\\\"$var\\\":\\\"$id\\\"";
	  else
		  tasks="$tasks,\\\"$var\\\":\\\"$id\\\"";
	  fi
	done < "$dirTests/tasks.txt";
	contest=$(($contest + 1));
	tasksNum=`wc -l < "$dirTests/tasks.txt"`;
	echo "('ProgrammingBasics$contest', '$dirTests', '/contests/ProgrammingBasics$contest', '{$tasks}', '{\\\"c\\\":\\\"C\\\",\\\"cpp\\\":\\\"C++\\\",\\\"py\\\":\\\"Python\\\",\\\"js\\\":\"Node.JS\\\"}', '${tasksNum}00', 0, 1, '', 'techedu'),"
	echo "('ProgrammingBasics$contest', '$dirTests', '/contests/ProgrammingBasics$contest', '{$tasks}', '{\\\"c\\\":\\\"C\\\",\\\"cpp\\\":\\\"C++\\\",\\\"py\\\":\\\"Python\\\",\\\"js\\\":\"Node.JS\\\"}', '${tasksNum}00', 0, 1, '', 'techedu')," >> contests

	echo "-------------------------------------" ; 
done

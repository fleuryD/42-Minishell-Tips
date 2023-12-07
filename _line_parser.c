/*


Parsing (sans la gestion des parentheses du bonus)
__________________________________________________


on a data->line qui vaut un truc du genre :

   echo    -n     -n   'hello $USER'  "salut $USER"  def  > file.txt && env | sort




On veut transformer ca en [tableau ou liste chainee] de tokens:


|	val			| type				| escape_env_var
|	-----------	| -----------		|-----------------
|	echo		| TK_TYPE_STR		|	0
|	-n			| TK_TYPE_STR		|	0
|	-n			| TK_TYPE_STR		|	0
|	hello $USER	| TK_TYPE_STR		|	 1 (car entre simples quotes)
|	salut $USER	| TK_TYPE_STR		|	0
|	def			| TK_TYPE_STR		|	0
|	>			| TK_TYPE_RED_OUT	|	0
|	file.txt	| TK_TYPE_STR		|	0
|	&&			| TK_TYPE_AND		|	0
|	env			| TK_TYPE_STR		|	0
|	|			| TK_TYPE_PIPE		|	0
|	sort		| TK_TYPE_STR		|	0



________________________________________________________________________________

ALGO :


parcourir line

	if is_white_space(current_char)
		current_char++


	else if current_char est dans "&|><"
		regarder si le char d'apres est identique ( >> ou << ou && ou ||)
		creer un token avec 1 OU 2 char et definir son type (ex: TK_TYPE_RED_OUT)
		current_char += 1 OU 2 (placer le curseur sur le char d'apres)


	else if current_char == doubleQuote
		int fin = get_index_of_next_doubleQuote(line, current_char ((+ 1)) )
		if (fin == -1)
			error: pas de quote fermante
			(On a pas a gerer)
			break ou return NULL ou ...
		creer un token avec le contenu entre les 2 doubleQuote (ft_substr) (sans les quotes !!!)
		token.type = TK_TYPE_STR
		token.escape_env_var = false (on remplacera les env_vars)
		placer le curseur sur le char d'apres la quote fermante


	else if current_char == simpleQuote
		... la meme chose
		token.escape_env_var = true (on NE remplacera PAS les env_vars)
		... la meme chose


	else
		(on est sur un mot:   echo, -n, $USER, ...)
		chercher la fin du mot et creer un token entre ces 2 char(ft_substr)
			==> (tant que char existe && char n'est pas dans "&|><(whiteSpace)" )
		token.type = TK_TYPE_STR
		token.escape_env_var = false (on remplacera les env_vars)
		placer le curseur sur le char d'apres le mot

































*/
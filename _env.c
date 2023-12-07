


/*


on utilise la copie (data.env) et pas le vrai env !!!!



env est un char** (tableau de string)
chaque string de ce tableau est de la forme : "key=value"

char **env =
[
	...
	DESKTOP_SESSION=ubuntu
	USER=dfleury
	XDG_MENU_PREFIX=gnome-
	XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session2
	GJS_DEBUG_OUTPUT=stderr
	HOME=/nfs/homes/dfleury
	QT_IM_MODULE=ibus
	....
]



on veut une fonction qui prend une key et env) et renvoit la value correspondante


exemple:

get_value_of_env_var("USER", env)  ====> return  "dfleury"
get_value_of_env_var("ABC", env)  ====> return  null





get_value_of_env_var(char *key, char **env)
{
	// A TESTER !

	parcourir data->env
		if (data->env[i] commence par env_var_name  &&  (le char d'apres == '=')  )
			return (ft_strdup(data->env[i] + ft_strlen(env_var_name) + 1)) // +1 pour sauter le '='
	return (NULL)
}






*/
























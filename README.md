# 42 Minishell Tips

Quelques tips pour le projet minishell de l'ecole 42

---

&nbsp;

&nbsp;

## Exemple de partage des taches:

Partagez vous le travail, en definissant exactement ce que chaque personne doit faire.

- Qu'est ce aue je recois en entree ?
- Qu'est ce que je dois renvoyer ?
- Qu'est ce que je dois faire avec les erreurs ?

Vous pourrez ainsi travailler en parallele, sans attendre que les autres aient fini.

### Creer les fonctions de la libft_extra

### Copier env dans data.env

```
- arg: char** env
- return: Rien ou data
```

- Ca prend 5 minutes si vous avez fait ft_strs_dup de la libft_extra

### Parsing

```
- arg: 1 str
- return: 1 [liste ou tableau] de tokens (voir structure token)
```

### Remplacer variables d'environnement dans les tokens

```
- arg: 1 [liste ou tableau] de tokens + env (les 2 sont dans data)
- return: 1 [liste ou tableau] de tokens avec les variables d'environnement remplacées
```

- Pas besoin d'attendre que le parsing soit fait (utilisez une "fausse" liste de tokens ecrite a la main)
- Reutilisez les fonctions que vous avez faites pour les buitins export et unset !!!

### Buitins (cd, echo, pwd, export, unset, env, exit)

```
- arg: A definir en groupe (voir fichier buitins)
- return: 0 ou 1 (ou autre code d'erreur)
```

- N'utilisez pas le "vrai" env, mais la copie (data->env)
- Pas besoin d'attendre que le parsing soit fait (utilisez des "faux" argc, argv, env ecrits a la main)
- Ajouter une fonction dans le libft_extra: ft_str_replace ??

### Executer une commande externe

```
- arg: A definir en groupe (voir fichier buitins)
- return: 0 ou 1 (ou autre code d'erreur)
```

- utilisez `execve` et `fork` avec le PATH de data->env

### Reflechir a comment vous allez regrouper tout ca !

- Pour une commande simple, il faut juste regarder le 1er token
  - Si ce 1er token est `echo, pwd, cd, export..`, on execute le buitin
  - Sinon on fait execve
- Comment faire des redirections ?
- Comment faire des pipes ?
- Comment enregistrer le status de la derniere commande ? ($?)

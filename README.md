# Pipex
<div align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/pipexm.png" alt="Pipex Badge"/>
</div>

## 📝 Résumé
**pipex** est un projet ou nous devons reproduire le comportement du pipe en shell. L'objectif est de comprendre et implémenter les mécanismes de communication entre processus en C, en recréant la fonctionnalité suivante :
```bash
< file1 cmd1 | cmd2 > file2
```

**Objectifs principaux :**
- Comprendre le fonctionnement des pipes, fork, et redirections
- Maîtriser la gestion des processus et leur communication
- Gérer les file descriptors et leur duplication
---

## 🔧 Installation
### Cloner le projet
```bash
git clone https://github.com/mello-sdn/Pipex.git
cd pipex
```

### Compilation
```bash
make
```

---

## 💻 Utilisation
### Programme pipex
```bash
# Exemple basique
./pipex infile "ls -l" "wc -l" outfile
# Équivaut à : < infile ls -l | wc -l > outfile

# Avec des commandes courantes
./pipex input.txt "grep Hello" "wc -w" output.txt

# Gestion d'erreurs
./pipex nonexistent.txt "cat" "wc -l" output.txt
# Gère le fichier inexistant et affiche l'erreur appropriée
```
---

## 📚 Points clés à retenir & ressources

### Concepts Système
- **Pipes** : Communication unidirectionnelle entre processus (fd[0] lecture, fd[1] écriture)
- **Fork** : Création de processus enfants et gestion du parent
- **Exec** : Remplacement du processus actuel par une nouvelle commande
- **Dup2** : Redirection des file descriptors (stdin, stdout)
- **Wait/Waitpid** : Synchronisation des processus parent/enfant

### Gestion d'Erreurs
- Fichiers inexistants ou sans permissions
- Commandes invalides ou introuvables dans PATH
- Gestion des codes de retour (127 pour commande introuvable, 126 pour permission denied)
- Fermeture appropriée de tous les file descriptors
- Gestion des leaks mémoire et des processus zombies

### Ressources
- [Man pages : pipe(2), fork(2), execve(2), dup2(2)](https://man7.org/linux/man-pages/)
- [Pipex Tester](https://github.com/vfurmane/pipex-tester)
---

## 💡 Conseils
- N'oubliez pas de fermer TOUS les file descriptors inutilisés
- Utilisez valgrind pour traquer les leaks : `valgrind --trace-children=yes ./pipex ...`
- Testez avec différents cas : fichiers inexistants, commandes invalides, permissions
- Vérifiez que votre programme se comporte exactement comme celui du shell
- Pensez à gérer la variable d'environnement PATH pour trouver les commandes et si PATH invalide bien free la mémoire alloué 
---

## ✔️ Note Finale
<br>
  <img width="199" height="170" alt="125" src="https://github.com/user-attachments/assets/c127bd3f-6bda-4633-80a0-b4efb9a120d6" />

# Signature
dir : /System/Volumes/Data/sgoinfre/Perso/ele-sage/Born2beroot/Born2beroot.vdi
Signature : 250d7373791d65c306bd0aefb042ff719e57be38

# Overview
Fonctionnement  d'une machine virtuelle :
    Une machine virtuelle fonctionne en créant un environnement logiciel simulant un ordinateur indépendant, qui tourne sur un ordinateur hôte. Le système d'exploitation invité installé sur la machine virtuelle agit comme s'il était installé directement sur l'ordinateur hôte, mais en réalité, il tourne en isolation de l'environnement d'exploitation hôte. Les ressources matérielles de l'ordinateur hôte, telles que la mémoire, le processeur et le stockage, sont allouées à la machine virtuelle pour lui permettre de fonctionner comme un ordinateur autonome. Cela permet aux utilisateurs de faire tourner plusieurs systèmes d'exploitation sur un seul ordinateur physique sans les faire interférer les uns avec les autres.

Choix de l'OS :
J'ai utilisé Debian car, il est plus facile à installer et à configurer que CentOS (et que je n'ai jamais utilisé CentOS auparavant).

Différence entre CentOS et Debian :
    1.
        Philosophie de développement: Debian est un système d'exploitation en développement libre avec une forte communauté de développeurs et de contributeurs, tandis que CentOS est un clone de la distribution Red Hat Enterprise Linux (RHEL) qui est principalement soutenu par une entreprise privée.
    2.
        Intervalles de mise à jour: Debian est connu pour ses mises à jour fréquentes et rapides avec une politique de mise à jour stricte, tandis que CentOS est plus conservateur en ce qui concerne les mises à jour, offrant une période de support plus longue pour chaque version.
    3.
        Applications pré-installées: Debian inclut un nombre important d'applications et de paquets pré-installés, tandis que CentOS en inclut moins, en se concentrant sur les fonctionnalités système de base.
    4.
        Cible d'utilisateurs: Debian s'adresse à un public plus large, incluant les utilisateurs de bureau et les développeurs, tandis que CentOS est principalement utilisé dans les entreprises et les centres de données pour les serveurs et les environnements de virtualisation.

Le but d'une machine virtuelle  :
    1.
        Isolation: Les applications et les systèmes d'exploitation fonctionnant sur des machines virtuelles sont isolés les uns des autres, ce qui empêche les erreurs de se propager entre les différents environnements.
    2.
        Tests et développement: Les développeurs peuvent utiliser des machines virtuelles pour tester leurs applications sur différents systèmes d'exploitation et configurations de matériel sans avoir à configurer de nombreux ordinateurs physiques.
    3.
        Compatibilité logicielle: Les utilisateurs peuvent faire tourner des applications qui ne sont pas compatibles avec leur système d'exploitation hôte en les exécutant dans une machine virtuelle.
    4.
        Sécurité: Les machines virtuelles peuvent être utilisées pour exécuter des applications à risque, telles que les navigateurs web, sans affecter le système d'exploitation hôte.

En somme, les machines virtuelles permettent de créer des environnements logiciels indépendants qui peuvent être utilisés pour diverses tâches, telles que le développement de logiciels, les tests de compatibilité, la sécurité et la virtualisation de serveurs.

Différence entre aptitude et apt :
    1.
        Interface utilisateur: Aptitude a une interface en mode texte plus avancée que apt, avec des fonctionnalités telles que la résolution automatique des dépendances et la gestion de la mémoire.
    2.
        Historique des mises à jour: Aptitude conserve un historique des mises à jour effectuées, ce qui peut être utile pour revenir à une version précédente si une mise à jour a causé des problèmes. Apt ne conserve pas ce genre d'historique.
    3.
        Capacité de résolution des dépendances: Aptitude est considéré comme supérieur à apt en matière de résolution des dépendances, car il peut gérer des situations complexes avec plus de facilité.
    4.
        Vitesse: Apt est considéré comme plus rapide que aptitude, car il est plus simple et ne comporte pas les fonctionnalités avancées de aptitude.

En fin de compte, le choix entre apt et aptitude dépend des préférences de l'utilisateur en termes de fonctionnalités et d'interface. De nombreux utilisateurs préfèrent apt pour sa simplicité et sa rapidité, tandis que d'autres préfèrent aptitude pour ses fonctionnalités avancées.

What is APPArmor :
AppArmor (Application Armor) est un système de sécurité pour Linux qui fournit une couche de sécurité additionnelle pour les applications en les isolant et en restreignant leurs actions. Il fonctionne en définissant des profils pour les applications qui spécifient les actions autorisées et les ressources auxquelles elles peuvent accéder.

AppArmor permet de limiter les dommages causés par des applications compromise en restreignant leurs activités à celles qui sont strictement nécessaires pour leur fonctionnement. Par exemple, un navigateur web pourrait être configuré pour ne pas avoir accès à certaines parties du système de fichiers ou à certaines fonctionnalités du système, ce qui empêcherait une attaque malveillante de se propager ou d'endommager les données système.

AppArmor est un système de sécurité souple et flexible qui peut être configuré pour répondre aux besoins de sécurité spécifiques d'une organisation ou d'un utilisateur. Il est compatible avec un grand nombre de distributions Linux et peut être utilisé en conjonction avec d'autres systèmes de sécurité, tels que SELinux et Firewall, pour renforcer la sécurité globale du système.

Check APPArmor status
sudo aa-status

Check
*  Script running every 10min
*  No graphical user interface
*  Password requested on boot up
*  Login with ele-sage
*  Password must follow rules

# Sudo
Check that the UFW service is started
sudo ufw status

Check that the SSH service is started
sudo service ssh status

Check that the operating system is Debian
cat /etc/os-release | grep PRETTY_NAME

Check that ele-sage is member of sudo and user42 groups
groups ele-sage

Create a new user
sudo adduser new_user

Assign password
Confirm it follows the password policy

Explain how password rules were setup
vi /etc/pam.d/common-password

Create group evaluating and add created user
sudo addgroup evaluating
sudo adduser new_user evaluating

Check that user belongs to new group
groups new_user

Explain value and operation of sudo with examples :
"sudo" est une commande utilisée sur les systèmes d'exploitation Unix-like pour exécuter une commande en tant qu'utilisateur root ou en tant qu'utilisateur autorisé. Cela permet à un utilisateur de déléguer temporairement les privilèges d'administration du système à une commande spécifique, sans devoir se connecter en tant qu'utilisateur root.

L'utilisation de sudo est souvent nécessaire pour effectuer des tâches administratives telles que la modification de fichiers de configuration système, l'installation de logiciels, la gestion des utilisateurs, etc.

Voici un exemple d'utilisation de sudo:
apt-get update # Error 13: Permission denied
sudo apt-get update

L'utilisation de sudo peut être réglementée par les administrateurs système en utilisant le fichier de configuration "sudoers", qui définit les utilisateurs autorisés à utiliser sudo et les commandes qu'ils peuvent exécuter. Cela permet de contrôler de manière fine les activités administratives sur le système et de garantir un niveau élevé de sécurité.

En résumé, sudo est un mécanisme de sécurité pratique qui permet aux utilisateurs de déléguer temporairement les privilèges d'administration du système, tout en fournissant un contrôle sur qui peut les utiliser et pour quoi.

Verify that the "/var/log/sudo/" folder exists and has at least one file:

Check sudo program is properly installed
dpkg -l | grep sudo

Assign new user to sudo group
sudo adduser new_user sudo

Show the implementation of the subject rules
vi /etc/sudoers.d/sudoconfig

Verify that the /var/log/sudo/ folder exists and has a file
sudo ls /var/log/sudo/

Check there is a history of commands using sudo
sudo cat /.../log # Input log
sudo cat /.../ttyout # Output log

Run a command using sudo and check if files updated
sudo apt update
sudo ls /var/log/sudo/00/00 # should have new folder

# UFW

Check that UFW is properly installed
dpkg -l | grep ufw

Check that it is working properly
sudo ufw status

Explain what UFW is and the value of using it :
    UFW (Uncomplicated Firewall) est un outil de gestion de pare-feu pour les systèmes d'exploitation basés sur Debian, tels que Ubuntu. Il a été conçu pour offrir une interface simple et intuitive pour gérer les règles de filtrage de paquets de la couche réseau d'un système.

L'utilisation de UFW présente plusieurs avantages :
    1.
        Facilité d'utilisation: UFW offre une interface en ligne de commande simple et intuitive qui permet de configurer et de gérer les règles de pare-feu en utilisant des commandes simples et concises.
    2.
        Sécurité accrue: en contrôlant les entrées et les sorties réseau d'un système, UFW peut aider à protéger le système contre les menaces réseau telles que les attaques par déni de service, les intrusions, etc.
    3.
        Amélioration de la performance réseau: en bloquant les paquets indésirables, UFW peut améliorer les performances du réseau en réduisant la charge sur le système.
    4.
        Personnalisation: UFW offre une grande flexibilité pour personnaliser les règles de filtrage de paquets en fonction des besoins spécifiques d'un système.

En conclusion, UFW est un outil pratique et utile pour gérer les règles de filtrage de paquets d'un système, en offrant une interface simple et intuitive pour une meilleure sécurité et une performance améliorée du réseau.

List active rules should include one for port 4242
sudo ufw status | grep 4242

Add a new rule for port 8080 :
sudo ufw allow 8080
sudo ufw status

List rules numbered :
sudo ufw status numbered
Delete the new rule :
sudo ufw delete $NUMBER

# SSH

Check that the SSH service is properly installed :
dpkg -l | grep openssh-server

Check that it is working properly :
sudo service ssh status

Explain what SSH is and the value of using it :
SSH signifie Secure Shell et c'est un protocole de communication sécurisé pour les systèmes d'exploitation informatiques. Il permet aux utilisateurs de se connecter à distance à un ordinateur et de contrôler ce dernier en toute sécurité en chiffrant les informations transmises.

L'utilisation de SSH apporte une valeur en termes de sécurité en offrant une protection contre les attaques telles que la interception et la modification des données en transit. De plus, cela permet aux utilisateurs de se connecter à distance de manière fiable et sécurisée, ce qui peut être très pratique pour la gestion de serveurs, la résolution de problèmes informatiques, etc.


Verify that the SSH service only uses port 4242 :
sudo service ssh status | grep listening
/or check configs
sudo vi /etc/ssh/sshd_config
sudo vi /etc/ssh/ssh_config 

Login with SSH from host machine :
ssh ele-sage@127.0.0.1 -p 4242 # or  
ssh ele-sage@0.0.0.0 -p 4242 # or
ssh ele-sage@localhost -p 4242

Make sure you cannot SSH login with root user
ele-sage@ele-sage42:~$ login root
login: Cannot possibly work without effective root


# PASSWORD

Check password policy rules
Password expiry: line 160 and 161.
vi /etc/login.defs
Password policy: line 25.
vi /etc/pam.d/common-password

Explain advantages of password policy and advantages and disadvantages of policy implementation :
    Les politiques de mots de passe sont des ensemble de règles et de recommandations définissant la complexité et la longueur requises pour les mots de passe d'un système. Elles ont pour objectif de renforcer la sécurité en limitant la facilité pour les attaquants de deviner ou de cracker les mots de passe.

Les avantages de l'implémentation d'une politique de mots de passe comprennent:
    1.
        Sécurité accrue: en imposant des exigences plus strictes pour les mots de passe, la politique peut réduire les risques d'intrusion et de piratage.
    2.
        Conformité aux normes de sécurité: en conformité avec les normes de sécurité industrielles, une politique de mots de passe peut aider à garantir que le système est protégé contre les menaces courantes.
    3.
        Facilitation de la gestion des mots de passe: en encourageant les utilisateurs à choisir des mots de passe complexes et uniques, la politique peut aider à réduire les problèmes de gestion de mots de passe tels que les réinitialisations fréquentes et les mots de passe partagés.

Cependant, il y a également des inconvénients potentiels à l'implémentation d'une politique de mots de passe, notamment:
    1.
        Complexité accrue: en imposant des exigences plus strictes pour les mots de passe, la politique peut rendre plus difficile pour les utilisateurs de choisir et de se rappeler de mots de passe complexes.
    2.
        Temps de formation accru: pour mettre en œuvre une politique de mots de passe efficacement, il peut être nécessaire de former les utilisateurs sur les exigences et les meilleures pratiques pour les mots de passe.
    3.
        Frustration des utilisateurs: en limitant la flexibilité des mots de passe, la politique peut causer de la frustration chez les utilisateurs qui peuvent se sentir limités dans leur choix de mots de passe.

En conclusion, bien que l'implémentation d'une politique de mots de passe puisse être utile pour renforcer la sécurité et améliorer la gestion des mots de passe, il est important de prendre en compte les inconvénients potentiels pour éviter les frustrations inutiles des utilisateurs.


# Hostname and Partitions

Check that the hostname of the machine is ele-sage42
uname -n
ou
hostname

Modify hostname with evaluator login and reboot to confirm change
sudo adduser new_user sudo
sudo login new_user
sudo vi /etc/hostname # change to new_user42
sudo reboot

Restore original hostname
sudo vi /etc/hostname # change to ele-sage42
sudo reboot

How to view partitions
lsblk

Brief explanation of how LVM works :
LVM (Logical Volume Manager) est un système de gestion de disques pour les systèmes d'exploitation Unix-like. Il permet de regrouper plusieurs disques physiques en un seul et même volume logique, offrant une flexibilité accrue pour la gestion de l'espace de stockage.

LVM utilise un modèle de couche d'abstraction pour gérer les disques et les volumes. Les disques physiques sont regroupés en groupes de volumes (ou "groupes de périphériques"), qui peuvent être vus comme un seul disque logique. Ce disque logique peut être divisé en partitions logiques appelées "volumes logiques", qui peuvent être utilisées comme n'importe quel autre disque physique.

Avec LVM, il est possible de redimensionner facilement les volumes logiques sans avoir à redémarrer le système ou à interrompre les activités en cours sur les disques. Il est également possible de déplacer des volumes logiques d'un disque physique à un autre sans interruption de service, ce qui peut être utile pour effectuer des mises à jour de disques ou pour équilibrer la charge de stockage.

En résumé, LVM permet une gestion plus flexible et plus efficace de l'espace de stockage sur les systèmes d'exploitation Unix-like en utilisant une couche d'abstraction pour regrouper plusieurs disques en un seul volume logique.

What is LVM about
La gestion des volumes logiques (LVM) est une forme de virtualisation du stockage qui offre aux administrateurs système une approche plus souple de la gestion de l'espace de stockage sur disque que le partitionnement traditionnel. L'objectif de LVM est de faciliter la gestion des besoins de stockage parfois contradictoires de plusieurs utilisateurs finaux.


# Monitoring script
Explanation of the monitoring script by showing the code :
dir : /home/ele-sage/bin/monitoring.sh

Ce script bash affiche les informations système de l'ordinateur sur le terminal. Il utilise des commandes telles que "uname", "grep", "awk", "df", "top", "who", "lsblk", "cat", "users", "hostname", "ip", "journalctl" pour collecter les informations suivantes :

Architecture du système d'exploitation
Nombre de processeurs physiques
Nombre de processeurs virtuels
Utilisation de la mémoire (en Mo utilisés et total)
Utilisation du disque dur (en Go utilisés et total)
Charge CPU
Date et heure du dernier démarrage
Utilisation de LVM (Logical Volume Manager)
Connexions TCP établies
Nombre d'utilisateurs connectés
Adresse IP et adresse MAC
Nombre de commandes exécutées en tant que superutilisateur
La sortie est ensuite affichée sur le terminal.


Disk :
La fonction (df) avec l'option -Bg retrouvera les informations sur les differentes partitions montees sur le systeme. 
Ensuite, les donnes seront pipe vers la commande (grep) qui recherchera toutes les occurences commencant (^) par "/dev/" 
et qui transferera le resultats dans une autre commande (grep), qui lui exclura "/boot/" des resultats. pour terminer,
le resultat sera pipe vers la commande (awk) qui au passage declare une variable "t_disk" et additionnes a l'interieur  
les differentes valeur de la colonne 2 qui represente l espace disque total de chacune des partitions.

LVM :
La condition (if) determinera l'action a prendre en fonction que le terme 'lvm' ce retrouve au moins fois 
ou pas dans a l'affichage de la commande (lsblk). Seul la colonne 'TYPE' affichee par (lsblk) sera garde grace avec 
la commande (cut). Ensuite la commande (grep) isolera les lignes ou l'occurence est trouvée. Puis finalement, 
la commande (wc -l) contera le nombre de ligne restante ce qui indiquera le nombre de fois que le terme 'lvm' est present.  

# Cron
What is cron :
    L'utilitaire de ligne de commande cron, également connu sous le nom de travail cron, est un planificateur de tâches sur les systèmes d'exploitation de type Unix. Les utilisateurs qui configurent et entretiennent des environnements logiciels utilisent cron pour planifier des tâches (commandes ou scripts shell) à exécuter périodiquement à des heures, dates ou intervalles fixes. Il automatise généralement la maintenance ou l'administration du système, bien que sa nature polyvalente le rende utile pour des choses comme le téléchargement de fichiers depuis Internet et le téléchargement d'e-mails à intervalles réguliers.


How to set up the script to run every 10mins
sudo crontab -e
Add following line
*/10 * * * * bash /home/ele-sage/bin/monitoring.sh

Verify correct functioning of the script
Check print out in console.

Change run of script to every minute
sudo crontab -e
Add following line
*/1 * * * * bash /home/ele-sage/bin/monitoring.sh

Make the script stop running after reboot without modifying it
Remove the scheduling line on the crontab
sudo crontab -e
Remove following line/s
@reboot bash /home/ele-sage/bin/monitoring.sh
*/1 * * * * /home/monitoring.sh
*  Restart server
*  Check script still exists in the same place
*  Check that its rights have remained the same
*  Check that it has not been modified


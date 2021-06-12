# Friends_game
Projet POO ROB4 2020/2021

Auteurs :
    COMBELLES Théo
    HENRY-SEIMANDI Camille

Liste des bibliothèques, frame work, outils externes :
    SFML

Manuel d'utilisation :
    Le jeu se base dans l'univers de Friends, il y a deux joueurs en compétitions. L'un, Joey, dont le but est de salir le plus possible (déplacement QSDZ). L'autre, Manica dont le but est de nettoyer le plus possible (déplacement flèches). Pour ce faire les joueurs disposent de 40 sec. De plus, le jeu est parsemé de quelques petit bonus.
    Le jeu démarre sur un menu (commande avec les flèches) qui permet de jouer, d'avoir accès aux règles et de quitter.

Conception du pgm :
La conception du jeu s'est faite étape par étape en commençant par la création du noyau (création de l'appartement, des salles, des joueurs...) avant de rajouter petit à petit les méthodes essentielles au bon déroulement du jeu. Puis nous avons décidé de rajouter quelques petits éléments pour permette une meilleure expérience de jeu (création d'un menu par exemple).
En ce qui concerne le fonctionnement, tout d'abord l'appartement est initialisé avec toutes les rooms, les doors et les bonus. Puis on fait appel à la méthode menu de game cela permet d'afficher le menu et de gerer les evenement de celui-ci. Cela se fait grâce à la classe menu et ses méthodes. Il y a alors trois cas de figure :
1 l'utilisateur selectionne quitter : le jeu se ferme,
2 l'utilisateur selectionne règles : le règles s'affichent (grâce à la méthode pop-up de Game),
3 l'utilisateur selectionne jouer : la méthode play de Game est appelée.

Tout se passe alors dans cette méthode play, c'est ici que nous créons et ajoutons les joueurs au jeu, nous gérons les animations, les sons, les événements, etc.
Comme événements, nous pouvons citer :
la gestion des deplacement qui se fait losqu'une touch QSDZ ou fleches est pressée (se fait dans la méthode play)
le calcul et l'affichage des scores (se fait dans la méthode play)
le calcul et l'affichage du chrono qui indique le temps de jeu (se fait dans la méthode play)
la gestion des objets (se fait dans la méthode inRoom de la classe Appartment) : si un jouer se trouve à la même position qu'un objet, on le rajoute à l'attrinut myObjet du joueur puis on le supprime des objets de la salle
la gestion de l'etat de la matrice data des salles (se fait dans la méthode inRoom de la classe Appartment) : si un joueur passe sur une case son état se met à jour par rapport à si c'est monica ou joey
la gestion des colisions (se fait dans la méthode update de la classe Player) : ??


Ce qui marche :
tout ce que nous avons implementer (cf.le paragraphe ci-dessus) fonctionne
Ce qui pourrait mieux marcher :
ajouter plus d'objets
position rand des objets
porte plus callées sur le dessin
Ce qui ne marche pas :
la gestion des accents avec la police choisie
les sons ne sont pas tous libre de droit

Nous sommes particulièrement fier de ce projet car nous avons globalement réussi à implementer tous ce qui était prévu. De plus, ça a presque toujours été un "plaisir" de travailler dessus car cela était payant et nous avons réussit à créer un jeu de a à z. Bien qu'il nous a fallut quelques temps pour nous familiariser avec la bibliothèque SFML, nous avons pu en tirer beaucoup (animations, sons).
De plus, il nous as été particulièrement agréable de travailler en binôme car la communication été très claire et les deux parties impliquées. #thamille_BestBinome

Explication de l'organisation au sein du binôme:
     ?

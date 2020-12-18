# 2020-ProjetC
## 目的
通过数组和函数的方式实现了集合的初始化，清空，赋值，添加元素，删除元素，输出，和交并补等运算，运用埃拉托斯特尼筛法来获得素数集合
## 实现
集合的定义
e[0] : numero de numbre dans cet ensemble. ( e[0] = 0 )
e[1] : capacite de cet ensemble. ( e[1] = n )
e[2]-e[CAP] 表示I在集合中是否存在
### 函数的功能和实现
1.int vide(ensemble e) 数组中的所有变量设为0
 Role : vide un ensemble e.  * 作用 : 清空一个集合。 
2.int initEns(ensemble e, int n) 先清空集合，把集合的个数设为n，最大值设为c
 Role : initialise un ensemble e a vide de capacite n.
 *作用 : 初始化容量为n的集合e。 */
3.int plein(ensemble e) 把e[2]之后的值都设为1
 * Role : remplit entierement un ensemble e.
 * e[2 ... n + 2] = 1
4.int estVide(ensemble e)
Role : teste si un ensemble e est vide ou pas.
检验 e[0]是否为0
5.int egal(ensemble e1, ensemble e2)
Role : teste si 2 ensembles e1 et e2 sont egaux ou pas.
检验e1[0]==e2[0],并检验e1[2-e1[0]]==e2[2-e2[0]]
6.int affecter(ensemble e1, ensemble e2)
Role : affecte un ensembles e2 a un ensemble e1
把e1中的每个值都赋值为e2相等
7.int appartient(ensemble e, int n)
Role : teste si entier n appartient a un ensemble e.
检验e[n+2]是否存在
8.int ajouter(ensemble e, int n)
Role : ajoute un entier n a un ensemble e.
把e[n+2]赋值为1
9.int enlever(ensemble e, int n)
 Role : enleve un entier n a un ensemble e.
10.int printEns(ensemble e)
Role : ecrit un ensemble e sur la sortie standard.
11 int intersection(ensemble e1, ensemble e2, ensemble e3)
Role : calcule e3 = e1 ∩ e2.
如果一个数两个集合都存在则添加到新的集合中，并把e3[0]加一 
e3[i] = (e1[i] & e2[i]);e3[0]+= (e1[i] & e2[I]);
12 int Union(ensemble e1, ensemble e2, ensemble e3)
Role : calcule e3 = e1 ∪ e2.
如果e1或者e2中存在某个数，则把它添加到新的集合中，并把e3[0]加一 
e3[i] = (e1[i] | e2[i]);e3[0]+= (e1[i] | e2[I]);
13 int difference(ensemble e1, ensemble e2, ensemble e3)
Role : calcule e3 = e1 - e2.
初始化e4为e1 ∩ e2,把e3赋值为e1
如果e2中的某个数出现在e4中则将它删去
14 int complementaire(ensemble e1, ensemble e2)
Role : calcule e2 complementaire de e1 dans l'ensemble plein.
把e2填满，如果e1中存在某个数出现，则将它删去
15.int diffSym(ensemble e1, ensemble e2, ensemble e3)
Role : calcule la difference symetrique e3 = e1 ∆ e2.
初始化e4=e1 ∩ e2,e5=e1 ∪ e2,计算e5=e4-e3
### 埃拉托斯特尼筛法
a)le crible contient tous les nombres de 2 `a n;
b)le plus petit nombre contenu dans le crible est premier :l’ajouter `a l’ensemble  ́esultat;
c)on l’enl`eve du crible ainsi que tous ses multiples;
d)si le crible n’est pas vide, on recommence `a partir de b);


/* Ce module definit les fonctions de TypeEnsemble.
 *
 * @author : KANG Jiale "kanngjle@gmail.com" et ZHANG Liyun "leo.zhangliyun@stu.xidian.edu.cn"
 * Creation @date : 03-Dec-2020 10:21
 * Last file update : 04-Dec-2020 23:15
 */

#include <stdio.h>
#include <stdlib.h>

#define CAPACITEMAX 1000
typedef int ensemble[CAPACITEMAX + 2];
/*
 * e[i] = 0 : numero (i - 2) n'est pas dans cet ensemble.
 * e[i] = 1 : numero (i - 2) est dans cet ensemble.
 * ( i >= 2 et i <= (n + 2) )
 *
 * e[i] = 0 : 数字 (i - 2) 不再集合e中。
 * e[i] = 1 : 数字 (i - 2) 在集合e中。
 * ( i >= 2 且 i <= (n + 2) )
 */

/***************************************************************************
 *              les functions qu'on utilise dans cet programme             *
 *                      程序中用到的函数                                          *
 ***************************************************************************/

int valid(ensemble e);
int initEns(ensemble e, int n);
int vide(ensemble e);
int plein(ensemble e);
int estVide(ensemble e);
int egal(ensemble e1, ensemble e2);
int affecter(ensemble e1, ensemble e2);
int appartient(ensemble e, int n);
int ajouter(ensemble e, int n);
int enlever(ensemble e, int n);
int printEns(ensemble e);
int printlnEns(ensemble e);
int intersection(ensemble e1, ensemble e2, ensemble e3);
int Union(ensemble e1, ensemble e2, ensemble e3);
int difference(ensemble e1, ensemble e2, ensemble e3);
int complementaire(ensemble e1, ensemble e2);
int diffSym(ensemble e1, ensemble e2, ensemble e3);

/*
 * Role : teste si ensemble e est valide ou pas.
 * 作用 : 测试集合e是否有效。
 */
int valid(ensemble e)
{
    return e != NULL;
}

/*
 * Role : vide un ensemble e.
 * 作用 : 清空一个集合。
 */
int vide(ensemble e)
{
    if(!valid(e))
    {
        fprintf(stderr, "Il y a une erreur pour un ensemble e est invalide!\n");
        return -1;
    }

    e[0] = 0;
    e[1] = 0;

    for(int i = 2; i < CAPACITEMAX + 2; i++)
        e[i] = 0;

    return 0;
}

/*
 * Role : initialise un ensemble e a vide de capacite n.
 * e[0] : numero de numbre dans cet ensemble. ( e[0] = 0 )
 * e[1] : capacite de cet ensemble. ( e[1] = n )
 *
 * 作用 : 初始化容量为n的集合e。
 * e[0] : 集合e中拥有的数字个数。
 * e[1] : 集合e的容量。
 */
int initEns(ensemble e, int n)
{

    if(n > CAPACITEMAX)
    {
        fprintf(stderr, "C'est une erreur pour n > CAPACITEMAX !\n");
        return -1;
    }

    vide(e);
    e[0] = 0;
    e[1] = n;
    return 0;
}

/*
 * Role : remplit entierement un ensemble e.
 * e[2 ... n + 2] = 1
 *
 * 作用 : 使集合e中拥有全部的数字(1，2，3，……，n)。
 * e[2 ... n + 2] = 1
 */
int plein(ensemble e)
{
    if(!valid(e))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e est invalide!\n");
        return -1;
    }

    e[0] = e[1];

    for(int i = 2; i < e[1] + 2; i++)
        e[i] = 1;

    return 0;
}

/*
 * Role : teste si un ensemble e est vide ou pas.
 * 作用 : 测试集合e是否为空。
 */
int estVide(ensemble e)
{
    if(!valid(e))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e est invalide!\n");
        return -1;
    }

    if(!e[0]) return 1;
    else return 0;
}

/*
 * Role : teste si 2 ensembles e1 et e2 sont egaux ou pas.
 * 作用 : 测试两个集合e1和e2是否相等。
 */
int egal(ensemble e1, ensemble e2)
{
    if(!valid(e1) || !valid(e2))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e1 et e2 sont invalides!\n");
        return -1;
    }

    if(e1[0] != e2[0]) return 0;

    for(int i = 2; i < CAPACITEMAX + 2; i++)
        if(e1[i] != e2[i])
            return 0;

    return 1;
}

/*
 * Role : affecte un ensembles e2 a un ensemble e1.
 * 作用 : 将集合e2复制到集合e1中。
 */
int affecter(ensemble e1, ensemble e2)
{
    if(!(valid(e1) && valid(e2)) && (e1[1] <= e2[1]))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e1 et e2 sont invalides!\n");
        return -1;
    }

    e1[0] = e2[0];
    e1[1] = e2[1];

    for(int i = 2; i < CAPACITEMAX + 2; i++)
        e1[i] = e2[i];

    return 0;
}

/*
 * Role : teste si entier n appartient a un ensemble e.
 * 作用 : 测试数字n是否在集合e中。
 */
int appartient(ensemble e, int n)
{
    if(!valid(e))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e est invalide!\n");
        return -1;
    }

    if(e[n + 2])
        return 1;
    else
        return 0;
}

/*
 * Role : ajoute un entier n a un ensemble e.
 * 作用 : 在集合e中加入数字n。
 */
int ajouter(ensemble e, int n)
{
    if(!(valid(e) && e[0] < e[1]))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e est invalide!\n");
        return -1;
    }

    if(e[0] == e[1])
    {
        fprintf(stderr, "Il n'y pas de CAPACITE!\n");
        return 0;
    }

    e[0]++;
    e[n + 2] = 1;
    return 0;
}

/*
 * Role : enleve un entier n a un ensemble e.
 * 作用 : 在集合e中删除数字n。
 */
int enlever(ensemble e, int n)
{
    if(!(valid(e) && e[0] > 0))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e est invalide!\n");
        return -1;
    }

    if(!appartient(e, n))
    {
        fprintf(stderr, "n n'est pas dans l'ensemble!\n");
        return 0;
    }

    e[0]--;
    e[n + 2] = 0;
    return 0;
}

/*
 * Role : ecrit un ensemble e sur la sortie standard.
 * 作用 : 输出集合e。
 */
int printEns(ensemble e)
{
    if(!valid(e))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e est invalide!\n");
        return -1;
    }

    printf("[ ");
    for(int i = 2; i < CAPACITEMAX + 2; i++)
        if(e[i])
            printf("%d ", i - 2);
    printf("]");
    return 0;
}

/*
 * Role : ecrit un ensemble e sur la sortie standard suivi d'un passage a ligne.
 * 作用 : 输出集合e并且在末尾换行。
 */
int printlnEns(ensemble e)
{
    if(!valid(e))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e est invalide!\n");
        return -1;
    }

    printEns(e);
    printf("\n");
    return 0;
}
 
/*
 * Role : calcule e3 = e1 ∩ e2.
 * 作用 : 计算集合e3是e1和e2的交集。
 */
int intersection(ensemble e1, ensemble e2, ensemble e3)
{
    if(!(valid(e1) && valid(e2) && valid(e3)))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e1, e2 et e3 sont invalide!\n");
        return -1;
    }

    int cnt = 0;

    for(int i = 2; i < CAPACITEMAX + 2; i++)
    {
        e3[i] = (e1[i] & e2[i]);
        cnt += (e1[i] & e2[i]);
    }

    e3[0] = cnt;
    return 0;
}

/*
 * Role : calcule e3 = e1 ∪ e2.
 * 作用 : 计算集合e3是e1和e2的并集。
 */
int Union(ensemble e1, ensemble e2, ensemble e3)
{
    if(!(valid(e1) && valid(e2) && valid(e3)))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e1, e2 et e3 sont invalides!\n");
        return -1;
    }

    int cnt = 0;

    for(int i = 2; i < CAPACITEMAX + 2; i++)
    {
        e3[i] = (e1[i] | e2[i]);
        cnt += (e1[i] | e2[i]);
    }

    e3[0] = cnt;
    return 0;
}

/*
 * Role : calcule e3 = e1 - e2.
 * 作用 : 计算集合e3是e1和e2的差集。
 */
int difference(ensemble e1, ensemble e2, ensemble e3)
{
    if(!(valid(e1) && valid(e2) && valid(e3)))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e1, e2 et e3 sont invalides!\n");
        return -1;
    }

    ensemble e4;
    initEns(e4, e1[1]);
    affecter(e3, e1);
    intersection(e1, e2, e4);

    for(int i = 2; i < CAPACITEMAX + 2; i++)
        if(e4[i])
            enlever(e3, i - 2);

    return 0;
}

/*
 * Role : calcule e2 complementaire de e1 dans l'ensemble plein.
 * 作用 : 计算集合e2是e1的补集。
 */
int complementaire(ensemble e1, ensemble e2)
{
    if(!(valid(e1) && valid(e2)))
    {
        fprintf(stderr, "Il y a une erreur pour ensemble e1 et e2 sont invalides!\n");
        return -1;

    }

    plein(e2);

    for(int i = 2; i < e1[1] + 2; i++)
        if(e1[i])
            enlever(e2, i - 2);

    return 0;
}

/*
 * Role : calcule la difference symetrique e3 = e1 ∆ e2.
 * 作用 : 计算集合e3是e1∆e2.
 */
int diffSym(ensemble e1, ensemble e2, ensemble e3)
{
    if(!(valid(e1) && valid(e2) && valid(e3)))
    {
        fprintf(stderr, "Il y une erreur pour ensemble e1, e2 et e3 sont invalides!\n");
        return -1;
    }

    ensemble e4, e5;
    intersection(e1, e2, e4);
    Union(e1, e2, e5);
    difference(e5, e4, e3);
    return 0;
}

/******************************************************************************
 *                          le programme principal                            *
 *                              主函数                                             *
 ******************************************************************************/

int main(void)
{
    //n est le capacite de ensemble.
    //n是集合的容量。
    int n = 50;
    //declarer des ensembles.
    //声明集合e
    ensemble e1, e2, e3, e4, e5, e6;

    //initialiser 2 ensembles e1 et e2 a une capacite de n.
    //初始化容量为n的集合e1，e2.
    initEns(e1, n);
    initEns(e2, n);

    //ajouter 2, 19, 31 dans e1 et 10, 19, 34 dans e2.
    //将数字2，19，31加入集合e1，10，19，34加入集合e2.
    ajouter(e1, 2);
    ajouter(e1, 19);
    ajouter(e1, 31);
    ajouter(e2, 10);
    ajouter(e2, 19);
    ajouter(e2, 34);

    //ecrire sur la s/s les ensembles e1 et e2.
    //输出集合e1和e2.
    printf("e1 = ");
    printlnEns(e1);
    printf("e2 = ");
    printlnEns(e2);

    //tester si 10 et 19 appartiennent a e1.
    //测试10和19是否在集合e1中。
    printf("%d\n", appartient(e1, 10));
    printf("%d\n", appartient(e1, 19));

    //ajouter 33 a e1 et e2.
    //将数字33加入集合e1和e2.
    ajouter(e1, 33);
    ajouter(e2, 33);

    //ecrire sur la s/s les ensembles e1 et e2.
    //输出集合e1和e2.
    printf("e1 = ");
    printlnEns(e1);
    printf("e2 = ");
    printlnEns(e2);

    //ecrire sur la s/s, l’intersection de e1 et e2.
    //输出集合e1和e2的交集
    initEns(e3, n);
    intersection(e1, e2, e3);//e3 = e1 ∩ e2
    printf("e1 ∩ e2 = ");
    printlnEns(e3);

    //ecrire sur la s/s, l’union de e1 et e2.
    //输出e1和e2的并集。
    initEns(e3, n);
    Union(e1, e2, e3);//e3 = e1 ∪ e2
    printf("e1 ∪ e2 = ");
    printlnEns(e3);

    //ecrire sur la s/s, la diﬀerence de e1 et e2.
    //输出e1和e2的差集。
    initEns(e3, n);
    difference(e1, e2, e3);//e3 = e1 - e2
    printf("e1 - e2 = ");
    printlnEns(e3);

    //ecrire sur la s/s, le complementaire de e1.
    //输出e1的补集。
    initEns(e3, n);
    complementaire(e1, e3);//e3 = ~e1
    printf("~e1 = ");
    printlnEns(e3);

    //ecrire sur la s/s, la diﬀerence symetrique de e1 et e2.
    //输出e1∆d2.
    initEns(e3, n);
    diffSym(e1, e2, e3);//e3 = e1 ∆ e2
    printf("e1 ∆ e2 =");
    printlnEns(e3);

    //veriﬁer que le complementaire de intersection de e1 et e2 est la reunion de leurs complementaires (loi de De Morgan).
    //~(e1 ∩ e2) == (~e1) ∪ (~e2)
    //验证德·摩尔根定律的成立。
    initEns(e3, n);
    initEns(e4, n);
    initEns(e5, n);
    initEns(e6, n);
    intersection(e1, e2, e3);//e3 = e1 ∩ e2
    complementaire(e3, e4);//e4 = ~e3
    complementaire(e1, e3);//e3 = ~e1
    complementaire(e2, e5);//e5 = ~e2
    Union(e3, e5, e6);//e6 = e3 ∪ e5
    printf("De Morgan : %d\n", egal(e4, e6));

    //aﬀecter e2 a e1 et veriﬁer que e1 = e2.
    //将e2复制到e1并验证e1是否等于e2.
    initEns(e2, n);
    affecter(e2, e1);
    printf("affectation : e1 = e2 => e1 == e2 = %d\n", egal(e1, e2));

    return  EXIT_SUCCESS;
}

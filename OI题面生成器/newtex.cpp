#include <cstdio>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
string GBKToUTF8(const string& strGBK)  
{  
    string strOutUTF8 = "";  
    WCHAR * str1;  
    int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);  
    str1 = new WCHAR[n];  
    MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);  
    n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);  
    char * str2 = new char[n];  
    WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);  
    strOutUTF8 = str2;  
    delete[]str1;  
    str1 = NULL;  
    delete[]str2;  
    str2 = NULL;  
    return strOutUTF8;  
}  
int main(){
    FILE *fout=fopen("task_gbk.tex","w");
    char title[100],t[4][100],lx[4][100],name[4][100];
    double time[4];
    int mem[4],num[4],x;
    char timecha[4][100],memcha[4][100];
    printf("�����뿼�����ƣ�");
    scanf("%s",title);
    for(int i=1; i<=3; i++){
        printf("\n\n*****�����������%d��������Ϣ��*****\n",i);
        printf("�����뱾����������ƣ�");
        scanf("%s",t[i]);
        printf("�����뱾���Ӣ�����ƣ�");
        scanf("%s",name[i]);
        printf("�����뱾�����Ŀ���ͣ�1����ͳ�ͣ�2���ύ���ͣ���");
        scanf("%d",&x);
        if(x==1){
            sprintf(lx[i],"��ͳ��");
            printf("�����뱾��ÿ�����Ե��ʱ�ޣ��룩��");
            scanf("%lf",&time[i]);
            sprintf(timecha[i],"%.1lf��",time[i]);
            printf("�����뱾���ڴ����ƣ�MB����");
            scanf("%d",&mem[i]);
            sprintf(memcha[i],"%dMB",mem[i]);
        }
        else{
            sprintf(lx[i],"�ύ����");
            sprintf(timecha[i],"N/A");
            sprintf(memcha[i],"N/A");
        }
        printf("�����뱾����Ե���Ŀ��");
        scanf("%d",&num[i]);
    }
    fprintf(fout,"\\documentclass[10.5pt,a4paper,openany]{book}\n");
    fprintf(fout,"\\usepackage{times}\n");
    fprintf(fout,"\\usepackage{mathptmx}\n");
    fprintf(fout,"\\usepackage[boldfont,slantfont]{xeCJK}\n");
    fprintf(fout,"\\setmainfont{Times New Roman}\n");
    fprintf(fout,"\\setsansfont{Times New Roman}\n");
    fprintf(fout,"\\setmonofont{Times New Roman}\n");
    fprintf(fout,"\\setCJKmainfont{����}\n");
    fprintf(fout,"\\setCJKsansfont{����}\n");
    fprintf(fout,"\\setCJKmonofont{����}\n");
    fprintf(fout,"\\usepackage{amsmath,amssymb,amsthm}\n");
    fprintf(fout,"\\usepackage{geometry}\n");
    fprintf(fout,"\\geometry{left=2.5cm,right=2.5cm,top=2.5cm,bottom=2.5cm}\n");
    fprintf(fout,"\\usepackage{fancyhdr}\n");
    fprintf(fout,"\\usepackage{lastpage}\n");
    fprintf(fout,"\\usepackage{titlesec}\n");
    fprintf(fout,"\\titleformat{\\section}{\\bf \\Large \\centering}{}{0em}{}\n");
    fprintf(fout,"\\setcounter{secnumdepth}{0}\n");
    fprintf(fout,"\\usepackage{indentfirst}\n");
    fprintf(fout,"\\newcommand{\\tabincell}[2]{\\begin{tabular}{@{}#1@{}}#2\\end{tabular}}\n");
    fprintf(fout,"\\begin{document}\n");
    fprintf(fout,"    \\renewcommand{\\baselinestretch}{1.25}\\normalsize\n");
    fprintf(fout,"    \\setlength{\\parindent}{2em}\n");
    fprintf(fout,"    \\setlength{\\abovedisplayskip}{1pt}\n");
    fprintf(fout,"    \\setlength{\\belowdisplayskip}{1pt}\n");
    fprintf(fout,"    \\pagestyle{fancy}\n");
    fprintf(fout,"    \\fancyhf{}\n");
    fprintf(fout,"    \\fancyfoot[c]{��\\thepage ҳ\\quad �� \\pageref{LastPage} ҳ}\n");
    fprintf(fout,"    \\renewcommand{\\headrulewidth}{0mm}\n");
    fprintf(fout,"    \\begin{center}\n");
    fprintf(fout,"        {\\bf \\LARGE %s}\n",title);
    fprintf(fout,"    \\end{center}\n\n");
    fprintf(fout,"    \\begin{center}\n");
    fprintf(fout,"        \\begin{tabular}{|p{3cm}|p{3cm}|p{3cm}|p{3cm}|}\n");
    fprintf(fout,"            \\hline\n");
    fprintf(fout,"            ��Ŀ���� & %s & %s & %s \\\\\\hline\n",t[1],t[2],t[3]);
    fprintf(fout,"            ��Ŀ���� & %s & %s & %s \\\\\\hline\n",lx[1],lx[2],lx[3]);
    fprintf(fout,"            ��ִ���ļ��� & %s & %s & %s \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"            �����ļ��� & %s.in & %s.in & %s.in \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"            ����ļ��� & %s.out & %s.out & %s.out \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"            ÿ�����Ե�ʱ�� & %s & %s & %s \\\\\\hline\n",timecha[1],timecha[2],timecha[3]);
    fprintf(fout,"            �ڴ����� & %s & %s & %s \\\\\\hline\n",memcha[1],memcha[2],memcha[3]);
    fprintf(fout,"            ���Ե���Ŀ & %d & %d & %d \\\\\\hline\n",num[1],num[2],num[3]);
    fprintf(fout,"            ÿ�����Ե��ֵ & %d & %d & %d \\\\\\hline\n",100/num[1],100/num[2],100/num[3]);
    fprintf(fout,"        \\end{tabular}\n");
    fprintf(fout,"    \\end{center}\n\n");
    fprintf(fout,"    �ύԴ�����ļ���\n\n");
    fprintf(fout,"    \\begin{center}\n");
    fprintf(fout,"        \\begin{tabular}{|p{3cm}|p{3cm}|p{3cm}|p{3cm}|}\n");
    fprintf(fout,"            \\hline\n");
    fprintf(fout,"            ����\\,\\makebox[27pt][l]{C++}���� & %s.cpp & %s.cpp & %s.cpp \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"            ����\\,\\makebox[27pt][l]{C}���� & %s.c & %s.c & %s.c \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"            ����\\,\\makebox[27pt][l]{Pascal}���� & %s.pas & %s.pas & %s.pas \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"        \\end{tabular}\n");
    fprintf(fout,"    \\end{center}\n\n");
    fprintf(fout,"    ����ѡ��\n\n");
    fprintf(fout,"    \\begin{center}\n");
    fprintf(fout,"        \\begin{tabular}{|p{3cm}|p{3cm}|p{3cm}|p{3cm}|}\n");
    fprintf(fout,"            \\hline\n");
    fprintf(fout,"            ����\\,\\makebox[27pt][l]{C++}���� & -lm & -lm & -lm \\\\\\hline\n");
    fprintf(fout,"            ����\\,\\makebox[27pt][l]{C}���� & -lm & -lm & -lm \\\\\\hline\n");
    fprintf(fout,"            ����\\,\\makebox[27pt][l]{Pascal}���� & & & \\\\\\hline\n");
    fprintf(fout,"        \\end{tabular}\n");
    fprintf(fout,"    \\end{center}\n\n");
    fprintf(fout,"    ע�����\n\n");
    fprintf(fout,"    1. �ļ���������������������ļ���������ʹ��Ӣ��Сд��\n\n");
    fprintf(fout,"    2. ��������˵��������ȽϷ�ʽ��Ϊ������ĩ�ո���ĩ�س���ȫ�ıȽϡ�\n\n");
    fprintf(fout,"    3. C/C++�к���main()�ķ���ֵ���ͱ�����int��������������ʱ�Ƿ���ֵ������0��\n\n");
    fprintf(fout,"    4. ��������˵��������ʱ�����κ��Ż�ѡ�\n\n");
    fprintf(fout,"    \\newpage\n\n");
    fprintf(fout,"    \\fancyhead[l]{%s}\n",title);
    fprintf(fout,"    \\fancyhead[r]{\\rightmark}\n\n");
    for(int i=1; i<=3; i++){
        fprintf(fout,"    \\section{\\MakeLowercase{%s(%s)}}\n\n",t[i],name[i]);
        fprintf(fout,"    {\\noindent \\bf ������������}\n\n");
        fprintf(fout,"    ��������\n\n");
        fprintf(fout,"    {\\noindent \\bf �������ʽ��}\n\n");
        fprintf(fout,"    �����ʽ\n\n");
        fprintf(fout,"    {\\noindent \\bf �������ʽ��}\n\n");
        fprintf(fout,"    �����ʽ\n\n");
        fprintf(fout,"    {\\noindent \\bf ���������������}\n\n");
        fprintf(fout,"    \\vspace*{2mm}\n\n");
        fprintf(fout,"    \\begin{tabular}{|p{5cm}|p{5cm}|}\n");
        fprintf(fout,"        \\hline\n");
        fprintf(fout,"        %s.in & %s.out \\\\\\hline\n",name[i],name[i]);
        fprintf(fout,"        \\tabincell{l}{input} & \\tabincell{l}{output} \\\\\\hline\n");
        fprintf(fout,"        %%\\tabincell�л�������\\\\���뱣������\\tabincell��������ͬ�������������\n");
        fprintf(fout,"    \\end{tabular}\n\n");
        fprintf(fout,"    \\vspace*{2mm}\n\n");
        fprintf(fout,"    {\\noindent \\bf �����ݹ�ģ��Լ����}\n\n");
        fprintf(fout,"    ���ݹ�ģ��Լ��\n");
        if(i<=2) fprintf(fout,"\n    \\newpage\n\n");
    }
    fprintf(fout,"\\end{document}\n");
    fclose(fout);
    ifstream in("task_gbk.tex");
    ofstream out("task.tex");
    string ss;
    while(getline(in,ss))
        out<<GBKToUTF8(ss)<<endl;
    in.close();
    out.close();
    system("del task_gbk.tex");
    return 0;
}
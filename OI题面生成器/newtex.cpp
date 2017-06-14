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
    printf("请输入考试名称：");
    scanf("%s",title);
    for(int i=1; i<=3; i++){
        printf("\n\n*****下面请输入第%d题的相关信息：*****\n",i);
        printf("请输入本题的中文名称：");
        scanf("%s",t[i]);
        printf("请输入本题的英文名称：");
        scanf("%s",name[i]);
        printf("请输入本题的题目类型（1：传统型，2：提交答案型）：");
        scanf("%d",&x);
        if(x==1){
            sprintf(lx[i],"传统型");
            printf("请输入本题每个测试点的时限（秒）：");
            scanf("%lf",&time[i]);
            sprintf(timecha[i],"%.1lf秒",time[i]);
            printf("请输入本题内存限制（MB）：");
            scanf("%d",&mem[i]);
            sprintf(memcha[i],"%dMB",mem[i]);
        }
        else{
            sprintf(lx[i],"提交答案型");
            sprintf(timecha[i],"N/A");
            sprintf(memcha[i],"N/A");
        }
        printf("请输入本题测试点数目：");
        scanf("%d",&num[i]);
    }
    fprintf(fout,"\\documentclass[10.5pt,a4paper,openany]{book}\n");
    fprintf(fout,"\\usepackage{times}\n");
    fprintf(fout,"\\usepackage{mathptmx}\n");
    fprintf(fout,"\\usepackage[boldfont,slantfont]{xeCJK}\n");
    fprintf(fout,"\\setmainfont{Times New Roman}\n");
    fprintf(fout,"\\setsansfont{Times New Roman}\n");
    fprintf(fout,"\\setmonofont{Times New Roman}\n");
    fprintf(fout,"\\setCJKmainfont{宋体}\n");
    fprintf(fout,"\\setCJKsansfont{黑体}\n");
    fprintf(fout,"\\setCJKmonofont{仿宋}\n");
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
    fprintf(fout,"    \\fancyfoot[c]{第\\thepage 页\\quad 共 \\pageref{LastPage} 页}\n");
    fprintf(fout,"    \\renewcommand{\\headrulewidth}{0mm}\n");
    fprintf(fout,"    \\begin{center}\n");
    fprintf(fout,"        {\\bf \\LARGE %s}\n",title);
    fprintf(fout,"    \\end{center}\n\n");
    fprintf(fout,"    \\begin{center}\n");
    fprintf(fout,"        \\begin{tabular}{|p{3cm}|p{3cm}|p{3cm}|p{3cm}|}\n");
    fprintf(fout,"            \\hline\n");
    fprintf(fout,"            题目名称 & %s & %s & %s \\\\\\hline\n",t[1],t[2],t[3]);
    fprintf(fout,"            题目类型 & %s & %s & %s \\\\\\hline\n",lx[1],lx[2],lx[3]);
    fprintf(fout,"            可执行文件名 & %s & %s & %s \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"            输入文件名 & %s.in & %s.in & %s.in \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"            输出文件名 & %s.out & %s.out & %s.out \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"            每个测试点时限 & %s & %s & %s \\\\\\hline\n",timecha[1],timecha[2],timecha[3]);
    fprintf(fout,"            内存限制 & %s & %s & %s \\\\\\hline\n",memcha[1],memcha[2],memcha[3]);
    fprintf(fout,"            测试点数目 & %d & %d & %d \\\\\\hline\n",num[1],num[2],num[3]);
    fprintf(fout,"            每个测试点分值 & %d & %d & %d \\\\\\hline\n",100/num[1],100/num[2],100/num[3]);
    fprintf(fout,"        \\end{tabular}\n");
    fprintf(fout,"    \\end{center}\n\n");
    fprintf(fout,"    提交源程序文件名\n\n");
    fprintf(fout,"    \\begin{center}\n");
    fprintf(fout,"        \\begin{tabular}{|p{3cm}|p{3cm}|p{3cm}|p{3cm}|}\n");
    fprintf(fout,"            \\hline\n");
    fprintf(fout,"            对于\\,\\makebox[27pt][l]{C++}语言 & %s.cpp & %s.cpp & %s.cpp \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"            对于\\,\\makebox[27pt][l]{C}语言 & %s.c & %s.c & %s.c \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"            对于\\,\\makebox[27pt][l]{Pascal}语言 & %s.pas & %s.pas & %s.pas \\\\\\hline\n",name[1],name[2],name[3]);
    fprintf(fout,"        \\end{tabular}\n");
    fprintf(fout,"    \\end{center}\n\n");
    fprintf(fout,"    编译选项\n\n");
    fprintf(fout,"    \\begin{center}\n");
    fprintf(fout,"        \\begin{tabular}{|p{3cm}|p{3cm}|p{3cm}|p{3cm}|}\n");
    fprintf(fout,"            \\hline\n");
    fprintf(fout,"            对于\\,\\makebox[27pt][l]{C++}语言 & -lm & -lm & -lm \\\\\\hline\n");
    fprintf(fout,"            对于\\,\\makebox[27pt][l]{C}语言 & -lm & -lm & -lm \\\\\\hline\n");
    fprintf(fout,"            对于\\,\\makebox[27pt][l]{Pascal}语言 & & & \\\\\\hline\n");
    fprintf(fout,"        \\end{tabular}\n");
    fprintf(fout,"    \\end{center}\n\n");
    fprintf(fout,"    注意事项：\n\n");
    fprintf(fout,"    1. 文件名（程序名和输入输出文件名）必须使用英文小写。\n\n");
    fprintf(fout,"    2. 除非特殊说明，结果比较方式均为忽略行末空格及文末回车的全文比较。\n\n");
    fprintf(fout,"    3. C/C++中函数main()的返回值类型必须是int，程序正常结束时是返回值必须是0。\n\n");
    fprintf(fout,"    4. 除非特殊说明，编译时不打开任何优化选项。\n\n");
    fprintf(fout,"    \\newpage\n\n");
    fprintf(fout,"    \\fancyhead[l]{%s}\n",title);
    fprintf(fout,"    \\fancyhead[r]{\\rightmark}\n\n");
    for(int i=1; i<=3; i++){
        fprintf(fout,"    \\section{\\MakeLowercase{%s(%s)}}\n\n",t[i],name[i]);
        fprintf(fout,"    {\\noindent \\bf 【问题描述】}\n\n");
        fprintf(fout,"    问题描述\n\n");
        fprintf(fout,"    {\\noindent \\bf 【输入格式】}\n\n");
        fprintf(fout,"    输入格式\n\n");
        fprintf(fout,"    {\\noindent \\bf 【输出格式】}\n\n");
        fprintf(fout,"    输出格式\n\n");
        fprintf(fout,"    {\\noindent \\bf 【输入输出样例】}\n\n");
        fprintf(fout,"    \\vspace*{2mm}\n\n");
        fprintf(fout,"    \\begin{tabular}{|p{5cm}|p{5cm}|}\n");
        fprintf(fout,"        \\hline\n");
        fprintf(fout,"        %s.in & %s.out \\\\\\hline\n",name[i],name[i]);
        fprintf(fout,"        \\tabincell{l}{input} & \\tabincell{l}{output} \\\\\\hline\n");
        fprintf(fout,"        %%\\tabincell中换行请用\\\\，请保持两个\\tabincell中行数相同，否则对齐会出错。\n");
        fprintf(fout,"    \\end{tabular}\n\n");
        fprintf(fout,"    \\vspace*{2mm}\n\n");
        fprintf(fout,"    {\\noindent \\bf 【数据规模与约定】}\n\n");
        fprintf(fout,"    数据规模与约定\n");
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
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
    char shortname[100],filename[100],ratio[100],title[100],institute[100],author[100],date[100];
    int x;
    printf("请输入文件名（不包括.tex后缀）：");
    scanf("%s",shortname);
    sprintf(filename,"%s.tex",shortname);
    printf("请选择页面长宽比（1. 4:3；2. 16:9）：");
    scanf("%d",&x);
    if(x==1) sprintf(ratio,"43");
    else sprintf(ratio,"169");
    printf("请输入标题：");
    scanf("%s",title);
    printf("请输入单位名称：");
    scanf("%s",institute);
    printf("请输入作者姓名：");
    scanf("%s",author);
    printf("请输入日期：");
    scanf("%s",date);
    fprintf(fout,"\\documentclass[aspectratio=%s]{beamer}\n",ratio);
    fprintf(fout,"\\usepackage[boldfont,slantfont]{xeCJK}\n");
    fprintf(fout,"\\usepackage{amsmath,amssymb,amsthm}\n");
    fprintf(fout,"\\definecolor{cmykgreen000}{cmyk}{0.5,0,1,0.2}\n");
    fprintf(fout,"\\usefonttheme[mathonly]{serif}\n");
    fprintf(fout,"\\usecolortheme[named=cmykgreen000]{structure}\n");
    fprintf(fout,"\\usetheme{Copenhagen}\n");
    fprintf(fout,"\\useoutertheme{miniframes}\n");
    fprintf(fout,"\\title{%s}\n",title);
    fprintf(fout,"\\author{%s\\quad %s}\n",institute,author);
    fprintf(fout,"\\date{%s}\n",date);
    fprintf(fout,"\\hypersetup{pdfpagemode={FullScreen}}\n");
    fprintf(fout,"\\begin{document}\n");
    fprintf(fout,"    \\renewcommand{\\baselinestretch}{1.25}\\normalsize\n");
    fprintf(fout,"    \\setlength{\\parindent}{0em}\n");
    fprintf(fout,"    \\setlength{\\abovedisplayskip}{1pt}\n");
    fprintf(fout,"    \\setlength{\\belowdisplayskip}{1pt}\n");
    fprintf(fout,"    \\maketitle\n\n");
    fprintf(fout,"    \\section{section1}\n");
    fprintf(fout,"    \\subsection{subsection1}\n\n");
    fprintf(fout,"    \\frame{\n");
    fprintf(fout,"        \\frametitle{frametitle}\n");
    fprintf(fout,"        text1\\pause\n\n");
    fprintf(fout,"        text2\\pause\n\n");
    fprintf(fout,"        text3\n");
    fprintf(fout,"    }\n");
    fprintf(fout,"    \\subsection{subsection2}\n\n");
    fprintf(fout,"    \\frame{\n");
    fprintf(fout,"        \\frametitle{frametitle}\n");
    fprintf(fout,"        text1\\pause\n\n");
    fprintf(fout,"        text2\\pause\n\n");
    fprintf(fout,"        text3\n");
    fprintf(fout,"    }\n");
    fprintf(fout,"\\end{document}\n");
    fclose(fout);
    ifstream in("task_gbk.tex");
    ofstream out(filename);
    string ss;
    while(getline(in,ss))
        out<<GBKToUTF8(ss)<<endl;
    in.close();
    out.close();
    system("del task_gbk.tex");
    FILE *fbat=fopen("compile3.bat","w");
    for(int i=1; i<=3; i++) fprintf(fbat,"xelatex %s\n",filename);
    fprintf(fbat,"del %s.aux\n",shortname);
    fprintf(fbat,"del %s.log\n",shortname);
    fprintf(fbat,"del %s.nav\n",shortname);
    fprintf(fbat,"del %s.out\n",shortname);
    fprintf(fbat,"del %s.snm\n",shortname);
    fprintf(fbat,"del %s.toc\n",shortname);
    fclose(fbat);
    return 0;
}
//---------------------------------------------------------------------------

#pragma hdrstop
#include <fstream.h>
#include <dir.h>
#include<windows.h>
#include<iostream.h>


//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        char dir[512]="";
        char *fl[1024];
        int i=0,j,done;
        struct ffblk file;
        ifstream in("input.txt",ios::in|ios::binary);
        if(!in)
                exit;
        while(in)
                in.get(dir[strlen(dir)]);
        dir[strlen(dir)]=0;
        in.close();
        setdisk(dir[0]-65);
        chdir(dir+2);
        //seach files
	done=findfirst("*.*", &file,7);
	while(!done)
	{
                if (file.ff_name[0]=='.')
		{
			done=findnext(&file);
			continue;
                }
                fl[i]=file.ff_name;
                i++;
		done=findnext(&file);
	}
        j=rand()%i;
        for(int k=strlen(dir),n=0;fl[j][n];k++,n++)
                dir[k]=fl[j][n];
        //dir="D:\\1.jpg";
        cout<<SystemParametersInfo(SPI_SETDESKWALLPAPER,0,"1.bmp",SPIF_SENDWININICHANGE | SPIF_SENDCHANGE);
        return 0;
}
//---------------------------------------------------------------------------

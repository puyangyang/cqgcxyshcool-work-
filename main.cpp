#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int isOperatpr(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/')
		return 1;
	else
		return 0;
}

void moveOperator(char *p){
	while(*p!='\0')
	{
		*p=*(p+1);
		p++;
	}
}
void moveOperand(float *p,float *end)
{
		while(p!=end)
		
			*p=*(p+1);
			p++;
	
}
int main()
{
	char strExp[]="1-2.5*4+10.2/5.1";
	char operators[10000]={'\0'};
	float operands[10000];
	int operatorsIdndex=0;
	for(int i=0;i < strlen(strExp);i++)
	{
		if(isOperatpr(strExp[i]))
		{
			operators[operatorsIdndex]=strExp[i];
            operatorsIdndex++;
		}
	}
	int operandsIndex=0;
	for(int k=0;k < strlen(strExp);k++)
	{
		char temp[100]={'\0'};
		int tempIndex=0;
		while(!isOperatpr(strExp[k]))
		{ 
			temp[tempIndex]=strExp[k];
			k++;
			tempIndex++;
		}
		float floatV=atof(temp);
		operands[operandsIndex++]=floatV;
	}
	/*for(int j=0;j<operandsIndex;j++)
	{
		printf("%0.lf\n",operands[j]);
	}*/
	char *poperator=operators;
	float *poperand=operands;
	while(*poperator!='\0')
	{
		if(*poperator=='*')
		{
            float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftOperand*rightOperand;
			*poperand=res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}
		else if(*poperator=='/')
		{
			float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftOperand/rightOperand;
			*poperand=res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);

		}
		else
		{
			poperator++; 
			poperand++;
		}
	}
    poperator=operators;
	poperand=operands;
	while(*poperator!='\0')
	{
		if(*poperator=='+') 
		{
            float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftOperand+rightOperand;
			*poperand=res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}
		else if(*poperator=='-')
		{
			float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftOperand-rightOperand;
			*poperand=res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);

		}
	}
	printf("the result is %0.2f\n",operands[0]);
	return 0;
}
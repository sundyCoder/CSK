#Sundy
##实现string 类。

	#include <iostream>
	using namespace std;
	class String{
		char *p;
	public:
		String():p(NULL){cout<<"String()"<<endl;}
		String(const String& s){
				cout<<"String(copy)"<<endl;
				if(s.p==NULL){
					p = NULL;
					return;
				}
				int cnt = 0;
				for (const char *q = s.p; *q!='\0'; ++q) {
					++cnt;
				}
				this->p = new char[cnt];
				for (int i = 0; i < cnt; ++i) {
					*(this->p+i) = *(s.p+i);
				}
			}
		String(const char* p){
			cout<<"String(const char*)"<<endl;
			int cnt = 0;
			for (const char *q = p; *q!='\0'; ++q) {
				++cnt;
			}
			this->p = new char[cnt];
			for (int i = 0; i < cnt; ++i) {
				*(this->p+i) = *(p+i);
			}
		}
		String(const int n,const char c){
			cout<<"String(int,char)"<<endl;
			p = new char[n];
			for (int i = 0; i < n; ++i) {
				*(p+i) = c;
			}
		}
		~String(){cout<<"~String()"<<endl;/*if(p!=NULL)*/delete[] p;}
		bool empty()const{return p==NULL;}
		int size()const{
			if(empty())return 0;
			int cnt = 0;
			for (char *q = p; *q!='\0'; ++q) {
				++cnt;
			}
			return cnt;
		}
		const char* c_str()const{
			int len = size();
			static char sp[256]={};
			int i;
			for (i = 0; i < len; ++i) {
				sp[i] = *(p+i);
			}
			sp[i]='\0';
			return sp;
		}
	
		String& operator=(const String &s){
				cout<<"String assignment"<<endl;
				if(p!=NULL){
					delete[] p;
					p = NULL;
				}
				if(s.p==NULL){
					return *this;
				}
				int cnt = 0;
				for (const char *q = s.p; *q!='\0'; ++q) {
					++cnt;
				}
				this->p = new char[cnt];
				for (int i = 0; i < cnt; ++i) {
					*(this->p+i) = *(s.p+i);
				}
				return *this;
			}
	
		String operator+(const String &s){
					int cnt1 = 0;
					if(p!=NULL)
						for (const char *q = p; *q!='\0'; ++q) {
							++cnt1;
						}
					int cnt2 = 0;
					if(s.p!=NULL)
					for (const char *q = s.p; *q!='\0'; ++q) {
						++cnt2;
					}
					int len = cnt1+cnt2;
					char buf[len+1];
					for (int i = 0; i < cnt1; ++i) {
						buf[i] = *(p+i);
					}
					for (int i = 0; i < cnt2; ++i) {
						buf[cnt1+i] = *(s.p+i);
					}
					buf[len]='\0';
					return String(buf);
				}
	
		String& operator+=(const String &s){
						int cnt1 = 0;
						if(p!=NULL)
							for (const char *q = p; *q!='\0'; ++q) {
								++cnt1;
							}
						int cnt2 = 0;
						if(s.p!=NULL)
						for (const char *q = s.p; *q!='\0'; ++q) {
							++cnt2;
						}
						int len = cnt1+cnt2;
						char * tp = new char[len+1];
						for (int i = 0; i < cnt1; ++i) {
							*(tp+i) = *(p+i);
						}
						for (int i = 0; i < cnt2; ++i) {
							*(tp+cnt1+i) = *(s.p+i);
						}
						*(tp+len)='\0';
						if(p!=NULL){
							delete[] p;
							p = NULL;
						}
						p = tp;
						return *this;
					}
	
		char& operator[](int i){
			if(i<0||i>=size()){
			static char ch = '\0';
				return ch;
			}
			return *(p+i);
		}
	
		bool operator==(const String &s){
			if(this==&s)return true;
			int len = size();
			if(len==s.size()){
				for (int i = 0; i < len; ++i) {
					if(*(p+i)!=*(s.p+i))return false;
				}
				return true;
			}
			return false;
		}
	
		bool operator!=(const String &s){
			return !operator==(s);
		}
	
		bool operator>(const String &s){
				if(empty())return false;
				int len1 = size();
				int len2 = s.size();
				int min = len1<len2?len1:len2;
				for (int i = 0; i < min; ++i) {
					if(*(p+i)>*(s.p+i))return true;
					else if(*(p+i)<*(s.p+i))return false;
				}
				if(len1>min)return true;
				else if(len2>min)return false;
				return false;
	
		}
	
		friend ostream& operator<<(ostream &os,const String &s){
			if(s.empty())return os;
			for (char *q = s.p; *q!='\0'; ++q) {
						os<<*q;
					}
			return os;
		}
	
		friend istream& operator>>(istream &is,String &s){
			if(s.p!=NULL){
				delete[] s.p;
				s.p = NULL;
			}
			char buf[256]={};
			unsigned int i = 0;
			for (i = 0; i < sizeof(buf); ++i) {
				char ch = cin.get();
				if(0==i){
					if(' '==ch||'\n'==ch||'\t'==ch){
						--i;
						continue;
					}
				}
				if(' '==ch||'\n'==ch){
					break;
				}
				buf[i] = ch;
			}
	
			s.p = new char[i+1];
			for (unsigned int j = 0; j < i; ++j) {
				*(s.p+j) = buf[j];
			}
			*(s.p+i)='\0';
			return is;
		}
	
	};
	
	int main2()
	{
	//	cout<<sizeof(String)<<endl;
	//	String s1;
	//	cout<<s1<<":"<<s1.size()<<endl;
	//	String s2("wepull");
	//	cout<<s2<<":"<<s2.size()<<endl;
		//String s3 = s2;
	//	String s3 = s1;
	//	String s3("good");
	//	s3 = s2;
	//	cout<<s3<<":"<<s3.size()<<endl;
	//	String s4 = s3+s2;
	//	String s4;
	//	s4 = s3+s2;
	//	cout<<s4<<":"<<s4.size()<<endl;
	//	s1+=s2;
	//	cout<<s1<<":"<<s1.size()<<endl;
	//	cin>>s1;
	//	cout<<s1<<":"<<s1.size()<<endl;
	//	for (int i = 0; i < s2.size(); ++i) {
	//			s2[i] = 'a'+i;
	//		}
	//	for (int i = 0; i < s2.size(); ++i) {
	//		cout<<s2[i]<<endl;
	//	}
	//	const char* cp = NULL;
	//	{
	//		String s5("good");
	//		cp = s5.c_str();
	//		String s6("wp");
	//		cp = s6.c_str();
	//	}
	//	cout<<"cstr:"<<cp<<endl;
		String s7(5,'w');
		String s8 = s7;
		cout<<(s7!=s8)<<endl;
		return 0;
	}

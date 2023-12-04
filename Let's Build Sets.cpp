#include <iostream>
#include <vector>
using namespace std;

class SET {
    public:
        vector<vector<int>> v;

        int belongs_to_set_check(int s, int data) {
            if (s<v.size()) {
                int count=0;
                for (int i=0; i<v[s].size(); i++) {
                    if (v[s][i]==data) {
                        count++;
                    }
                }
                if (count==0) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
            else {
                return -1;
            }
        }

        void insert_element(int s, int data) {
            if (s<v.size()) {
                if (belongs_to_set_check(s,data)==0) {
                    int position=0;
                    for (int i=0; i<v[s].size(); i++) {
                        if (v[s][i]<data) {
                            position++;
                        }
                    }
                    v[s].insert(v[s].begin()+position, data);
                }
            }
            else {
                v.push_back({data});
            }
            cout<<v[s].size()<<endl;
        }

        void delete_element(int s, int data) {
            if (s<v.size()) {
                int position=-1;
                for (int i=0; i<v[s].size(); i++) {
                    if (v[s][i]==data) {
                        position=i;
                    }
                }
                if (position!=-1) {
                    for (int i=position; i<v[s].size()-1; i++) {
                        v[s][i]=v[s][i+1];
                    }
                    v[s].pop_back();
                }
                cout<<v[s].size()<<endl;
            }
            else {
                cout<<-1<<endl;
            }
        }

        void belongs_to_set(int s, int data) {
            if (s<v.size()) {
                int count=0;
                for (int i=0; i<v[s].size(); i++) {
                    if (v[s][i]==data) {
                        count++;
                    }
                }
                if (count==0) {
                    cout<<0<<endl;
                }
                else {
                    cout<<1<<endl;
                }
            }
            else {
                cout<<-1<<endl;
            }
        }

        void set_union (int s1, int s2) {
            int n=v.size();
            if (s1<n && s2<n) {
                vector<int> dummy;
                int c1=0, c2=0;
                int n1 = v[s1].size();
                int n2 = v[s2].size();
                while (c1<n1 && c2<n2) {
                    if (v[s1][c1]==v[s2][c2]) {
                        dummy.push_back(v[s1][c1]);
                        c1++; c2++;
                    }
                    else if (v[s1][c1]>v[s2][c2]) {
                        dummy.push_back(v[s2][c2]);
                        c2++;
                    }
                    else if (v[s1][c1]<v[s2][c2]) {
                        dummy.push_back(v[s1][c1]);
                        c1++;
                    }
                }
                while (c1<n1) {
                    dummy.push_back(v[s1][c1]);
                    c1++;
                }
                while (c2<n2) {
                    dummy.push_back(v[s2][c2]);
                    c2++;
                }
                v[s1].clear();
                v[s1]=dummy;
                cout<<v[s1].size()<<endl;
            }
            else if (s1>=n && s2>=n) {
                v.push_back({});
                v.push_back({});
                cout<<0<<endl;
            }
            else if (s1==n && s2<n) {
                v.push_back({});
                v[s1]=v[s2];
                cout<<v[s1].size()<<endl;
            }
            else if (s1<n && s2==n) {
                v.push_back({});
                cout<<v[s1].size()<<endl;
            }
        }

        void set_intersection (int s1, int s2) {
            int n=v.size();
            if (s1<n && s2<n) {
                int c1=0, c2=0;
                vector<int> dummy={};
                while (c1<v[s1].size() && c2<v[s2].size()) {
                    if (v[s1][c1]==v[s2][c2]) {
                        dummy.push_back(v[s1][c1]);
                        c1++; c2++;
                    }
                    else if (v[s1][c1]>v[s2][c2]) {
                        c2++;
                    }
                    else if (v[s1][c1]<v[s2][c2]) {
                        c1++;
                    }
                }
                v[s1].clear();
                v[s1]=dummy;
                cout<<v[s1].size()<<endl;
                

            }
            else if (s1>=n && s2>=n) {
                v.push_back({});
                v.push_back({});
                cout<<0<<endl;
            }
            else if (s1==n && s2<n) {
                v.push_back({});
                cout<<0<<endl;
            }
            else if (s1<n && s2==n) {
                v.push_back({});
                v[s1].clear();
                cout<<0<<endl;
            }
        }

        void set_size(int s) {
            if (s<v.size()) {
                cout<<v[s].size()<<endl;
            }
            else {
                v.push_back({});
                cout<<0<<endl;
            }
        }

        void set_difference(int s1, int s2) {
            int n=v.size();
            if (s1<n && s2<n) {
                vector<int> dummy = {};
                int c1=0, c2=0;
                int n1 = v[s1].size();
                int n2 = v[s2].size();
                while (c1<n1 && c2<n2) {
                    if (v[s1][c1]==v[s2][c2]) {
                        c1++; c2++;
                    }
                    else if (v[s1][c1]>v[s2][c2]) {
                        c2++;
                    }
                    else if (v[s1][c1]<v[s2][c2]) {
                        dummy.push_back(v[s1][c1]);
                        c1++;
                    }
                }
                while (c1<n1) {
                    dummy.push_back(v[s1][c1]);
                    c1++;
                }
                v[s1].clear();
                v[s1]=dummy;
                cout<<v[s1].size()<<endl;
            }
            else if (s1>=n && s2>=n) {
                v.push_back({});
                v.push_back({});
                cout<<0<<endl;
            }
            else if (s1==n && s2<n) {
                v.push_back({});
                cout<<0<<endl;
            }
            else if (s1<n && s2==n) {
                v.push_back({});
                cout<<v[s1].size()<<endl;
            }
        }

        void set_symmetric_difference(int s1, int s2) {
            int n=v.size();
            if (s1<n && s2<n) {
                vector<int> dummy = {};
                int c1=0, c2=0;
                int n1 = v[s1].size();
                int n2 = v[s2].size();
                while (c1<n1 && c2<n2) {
                    if (v[s1][c1]==v[s2][c2]) {
                        c1++; c2++;
                    }
                    else if (v[s1][c1]>v[s2][c2]) {
                        dummy.push_back(v[s2][c2]);
                        c2++;
                    }
                    else if (v[s1][c1]<v[s2][c2]) {
                        dummy.push_back(v[s1][c1]);
                        c1++;
                    }
                }
                while (c1<n1) {
                    dummy.push_back(v[s1][c1]);
                    c1++;
                }
                while (c2<n2) {
                    dummy.push_back(v[s2][c2]);
                    c2++;
                }
                v[s1].clear();
                v[s1]=dummy;
                cout<<v[s1].size()<<endl;
                }
            else if (s1>=n && s2>=n) {
                v.push_back({});
                v.push_back({});
                cout<<0<<endl;
            }
            else if (s1==n && s2<n) {
                v.push_back({});
                v[s1]=v[s2];
                cout<<v[s1].size()<<endl;
            }
            else if (s1<n && s2==n) {
                v.push_back({});
                cout<<v[s1].size()<<endl;
            }
        }

        void print_set(int s) {
            if (s<v.size() && v[s].size()!=0) {
                for (int i=0; i<v[s].size()-1; i++) {
                    cout<<v[s][i]<<",";
                    }
                    cout<<v[s][v[s].size()-1]<<endl;
            }
            else {
                cout<<endl;
            }
        }
};


int main () {

    SET s;
    int a=0, b=0, c=0;
    while(cin>>a) {
        
        //taking the input from user:
        if ((a>=1 && a<=5)||(a==7)||(a==8)) {
            cin>>b;
            cin>>c;
        }
        else if (a==6||a==9) {
            cin>>b;
        }


        //calling the insert function:
        if (a==1) {
            s.insert_element(b,c);
        }
        //calling the delete function:
        if (a==2) {
            s.delete_element(b,c);
        }
        //calling the belongs_to function:
        if (a==3) {
            s.belongs_to_set(b,c);
        }
        //calling the union function:
        if (a==4) {
            s.set_union(b,c);
        }
        //calling the intersection function:
        if (a==5) {
            s.set_intersection(b,c);
        }
        //calling the size function:
        if (a==6) {
            s.set_size(b);
        }
        //calling the difference function:
        if (a==7) {
            s.set_difference(b,c);
        }
        //calling the symmetric difference function:
        if (a==8) {
            s.set_symmetric_difference(b,c);
        }
        //calling the print function
        if (a==9) {
            s.print_set(b);
        }
    }

    return 0;
}
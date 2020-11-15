#include "C.h"
    static bool cmp(string &a,string &b){
        int size_a = a.size();
        int size_b = b.size();
        int size = min(size_a,size_b);
        for(int i=0;i<size;i++){
            if(a[i]>b[i]) return 1;
            else if(a[i]<b[i]) return 0;
        }
        if(size_a>size_b){
            string s = a.substr(size);
            return cmp(s,b);
        }
        else if(size_a<size_b){
            string s = b.substr(size);
            cout<<a<<endl;
            return cmp(a,s);
        }
        else return 1;
    } 
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        string res;
        if(nums.size()==0) return res;
        for(auto i:nums)
            vs.push_back(to_string(i));
        sort(vs.begin(),vs.end(),cmp);
        if(vs[0]=="0") return "0";
        for(auto i:vs)
            res+=i;
        
        return res;
    }
int main(){
    vector<int> vi={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string s = largestNumber(vi);
    cout<<s<<endl;
    return 0;
}


// BAD WAY #################################################################################################

#include<bits/stdc++.h>
using namespace std;

class DocumentEditor{
    private:
    vector<string>documentElements;
    string renderedDocument;

    public:
    void addText(string text){
        documentElements.push_back(text);

    }

    void addImage(string Imagepath){
        documentElements.push_back(Imagepath);

    }

    string renderDocument(){

        if(renderedDocument.empty()){
            string result;
            for (auto element:documentElements){
                if (element.size()>4 && (element.substr(element.size()-4)==".jpg" ||
                element.substr(element.size()-4)==".png") ){
                    result+="[image:"+element+"]" + "\n";
                }
                else{
                    result+=element+"\n";
                }
                renderedDocument=result;
                
            }

        }
        return renderedDocument;
    }

    void saveToFile(){
        ofstream file("ducument.txt");
        if(file.is_open()){
            file<<renderDocument();
            file.close();
            cout<<"Document saved to document.txt "<<endl;

        }
        else{
            cout<<"Error: unable to open the file: "<<endl;
        }

    }

};

int main(){
    DocumentEditor editor;
    editor.addText("Hello world!");
    editor.addImage("picture.png");
    editor.addText("This is the document Editor");
    cout<<editor.renderDocument()<<endl;

    editor.saveToFile();
    return 0;
}
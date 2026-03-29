

// BAD WAY #################################################################################################

// #include<bits/stdc++.h>
// using namespace std;

// class DocumentEditor{
//     private:
//     vector<string>documentElements;
//     string renderedDocument;

//     public:
//     void addText(string text){
//         documentElements.push_back(text);

//     }

//     void addImage(string Imagepath){
//         documentElements.push_back(Imagepath);

//     }

//     string renderDocument(){

//         if(renderedDocument.empty()){
//             string result;
//             for (auto element:documentElements){
//                 if (element.size()>4 && (element.substr(element.size()-4)==".jpg" ||
//                 element.substr(element.size()-4)==".png") ){
//                     result+="[image:"+element+"]" + "\n";
//                 }
//                 else{
//                     result+=element+"\n";
//                 }
//                 renderedDocument=result;
                
//             }

//         }
//         return renderedDocument;
//     }

//     void saveToFile(){
//         ofstream file("ducument.txt");
//         if(file.is_open()){
//             file<<renderDocument();
//             file.close();
//             cout<<"Document saved to document.txt "<<endl;

//         }
//         else{
//             cout<<"Error: unable to open the file: "<<endl;
//         }

//     }

// };

// int main(){
//     DocumentEditor editor;
//     editor.addText("Hello world!");
//     editor.addImage("picture.png");
//     editor.addText("This is the document Editor");
//     cout<<editor.renderDocument()<<endl;

//     editor.saveToFile();
//     return 0;
// }


// #############################################################################################################################

// GOOD WAY
#include<bits/stdc++.h>
using namespace std;

class DocumentElement{
    public:
    virtual string render()=0;


};

class TextElement:public DocumentElement{
    private:
    string text;

    public:
    TextElement(string text){
        this->text=text;

    }

    string render() override {
        return text;

    }
};

class ImageElement:public DocumentElement{
    private:
    string imagepath;
    public:

    ImageElement(string imagepath){
        this->imagepath=imagepath;
    }

    string render() override{
        return "[image" +imagepath +"]";

    }
};


class NewLinElement:public  DocumentElement{
    public:
    string render() override{
        return "\n";
    }
};

class TabSpaceElement: public DocumentElement{
    public:
    string render() override{
        return "\t";
    }
};


class Document{
    private:
    vector<DocumentElement*> documentElements;

    public:
       void addElement(DocumentElement* element){
        documentElements.push_back(element);
       }

       string render(){
        string result;
        for (auto element:documentElements){
            result+=element->render();
        }
        return result;
       }


};

class Persistence{
    public:
    virtual void save(string data)=0;

};

class FileStorage:public Persistence{
    public:
    void save(string data){
        ofstream outfile("document.txt");
        if(outfile){
            outfile<<data;
            outfile.close();
            cout<<"Document aved to document.txt "<<endl;
        }
        else{
            cout<<"ERROR:  unable to save the file "<<endl;
        }
    }
};

class DocumentEditor{
    private:
    Persistence* storage;
    Document* document;
    string renderedDocument;

    public:
    DocumentEditor(Document* document,Persistence* storage){
        this->storage=storage;
        this->document=document;

    }

    void addText(string text){
        document->addElement(new TextElement(text));
    }

    void addImage(string imagepath){
        document->addElement(new ImageElement(imagepath));
    }


    void addNewline(){
        document->addElement(new NewLinElement());
    }
    void addTabSpace(){
        document->addElement(new TabSpaceElement());
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            renderedDocument=document->render();


        }

        return renderedDocument;

    }

    void saveDocument(){
        storage->save(renderDocument());
    }

};

int main(){
    Document* document=new Document();
    Persistence* persistence=new FileStorage();

    DocumentEditor* editor=new DocumentEditor(document, persistence);

    editor->addText("Hello World");
    editor->addNewline();
    editor->addImage("ipicture.png");
    editor->addNewline();
    editor->addTabSpace();
    editor->addText("dfghjk dfghjk sdfgh");
    editor->addNewline();
    editor->addImage("ipicture.jpg");

    cout<<editor->renderDocument()<<endl;
    editor->saveDocument();

    return 0;





}


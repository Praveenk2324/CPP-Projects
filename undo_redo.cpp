#include<iostream>
#include<stack>
using namespace std;

enum OperationType { INSERT, DELETE };

struct Action {
    OperationType type;
    char character;
    int index;
};

class TextEditor {
private:
    string textBuffer;
    stack<Action> undoStack;
    stack<Action> redoStack;

public:
    void write(char c, int index){
        if (index < 0 || index > textBuffer.length()){
            cout << "Invalid index!" << endl;
            return;
        }
        //.insert(position, count, character);
        textBuffer.insert(index, 1, c);

        Action newAction = {INSERT, c, index};
        undoStack.push(newAction);

        while(!redoStack.empty()){
            redoStack.pop();
        }        
    }

    void remove(int index){
        if (index < 0 || index >= textBuffer.length()) {
            cout << "Invalid index!" << endl;
            return;
        }

        char c = textBuffer[index];

        textBuffer.erase(index,1);

        Action newAction = { DELETE, c, index};
        undoStack.push(newAction);

        while(!redoStack.empty()){
            redoStack.pop();
        }
    }

    void undo(){
        if(undoStack.empty()){
            cout <<"Nothing to undo!" << endl;
            return;
        }

        Action lastAction = undoStack.top();
        undoStack.pop();

        redoStack.push(lastAction);

        if (lastAction.type == INSERT) {
            textBuffer.erase(lastAction.index, 1);
        } else if (lastAction.type == DELETE) {
            textBuffer.insert(lastAction.index, 1, lastAction.character);
        }
    }

    void redo(){
        if(redoStack.empty()){
            cout << "Nothing to redo" << endl;
            return;
        }

        Action actionToRedo = redoStack.top();
        redoStack.pop();

        undoStack.push(actionToRedo);

        if(actionToRedo.type == INSERT) {
            textBuffer.insert(actionToRedo.index, 1, actionToRedo.character);

        }else if (actionToRedo.type==DELETE){
            textBuffer.erase(actionToRedo.index, 1);
        }
    }
    void printBuffer() {
        cout << "Current Text: \"" << textBuffer << "\"" << endl;
    }
};
int main() {
    TextEditor editor;

    cout << "--- 1. Typing 'Hi' ---" << endl;
    editor.write('H', 0);
    editor.write('i', 1);
    editor.printBuffer(); // Output: "Hi"

    cout << "\n--- 2. Undo 'i' ---" << endl;
    editor.undo();
    editor.printBuffer(); // Output: "H"

    cout << "\n--- 3. Redo 'i' ---" << endl;
    editor.redo();
    editor.printBuffer(); // Output: "Hi"

    cout << "\n--- 4. Delete 'H' ---" << endl;
    editor.remove(0);
    editor.printBuffer(); // Output: "i"

    cout << "\n--- 5. Undo Delete (Bring 'H' back) ---" << endl;
    editor.undo();
    editor.printBuffer(); // Output: "Hi"
    
    return 0;
}
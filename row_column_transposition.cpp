#include <iostream> 
    #include <string> 
    using namespace std; 
    int main() { 
        const int MAX_WORDS = 100; // Maximum number of words 
        const int MAX_LENGTH = 100; // Maximum length of each word 
        // Buffer for the input sentence 
        char sentence[MAX_WORDS * MAX_LENGTH];  
        cout << "Enter a sentence: "; 
        cin.getline(sentence, sizeof(sentence)); 
        // 2D array to store words 
        char words[MAX_WORDS][MAX_LENGTH] = {0};  

        int word_count = 0, max_word_length = 0, current_word_length = 0;  
        // Tokenize the sentence into words 
        for (int i = 0, j = 0; sentence[i] != '\0'; ++i) { 
            if (sentence[i] != ' ') { 
                words[word_count][j++] = sentence[i]; 
                current_word_length++; 
            } else { 
                words[word_count][current_word_length] = '\0';
                if (current_word_length > max_word_length) max_word_length = current_word_length; 
                current_word_length = 0; word_count++; j = 0; 
            } 
        } 
        // Ensure the last word is considered 
        words[word_count][current_word_length] = '\0'; 
        if (current_word_length > max_word_length) max_word_length = current_word_length; 
        word_count++; 
        // Create a matrix of words padded with '*' 
        char matrix[MAX_WORDS][MAX_LENGTH] = {0};  

        for (int i = 0; i < word_count; i++) { 

            for (int j = 0; j < max_word_length; j++) { 

                if (words[i][j] != '\0') matrix[i][j] = words[i][j]; 
                else matrix[i][j] = '*'; 
            } 
        }
        // Print the original matrix 
        cout << "Original Matrix:" << endl;  
        for (int i = 0; i < word_count; i++) { 

            for (int j = 0; j < max_word_length; j++) cout << matrix[i][j] << ' '; 
            cout << endl; 
        } 
        // Row transposition: Move the last row to the first position 
        char temp[MAX_LENGTH] = {0};  
        for (int j = 0; j < max_word_length; j++) temp[j] = matrix[word_count - 1][j]; 

        for (int i = word_count - 1; i > 0; i--) { 

            for (int j = 0; j < max_word_length; j++) matrix[i][j] = matrix[i - 1][j]; 
        } 
        for (int j = 0; j < max_word_length; j++) matrix[0][j] = temp[j]; 
        // Print the row-transposed matrix 
        cout << "\nRow Transposed Matrix:" << endl;  

        for (int i = 0; i < word_count; i++) { 

            for (int j = 0; j < max_word_length; j++) cout << matrix[i][j] << ' '; 

            cout << endl; 

        } 
        // Column transposition: Move the last column to the first position 

        for (int i = 0; i < word_count; i++) { 

            char temp_col = matrix[i][max_word_length - 1]; 

            for (int j = max_word_length - 1; j > 0; j--) matrix[i][j] = matrix[i][j - 1]; 

            matrix[i][0] = temp_col; 

        }
        // Print the column-transposed matrix 
        cout << "\nColumn Transposed Matrix:" << endl;  
        for (int i = 0; i < word_count; i++) { 
            for (int j = 0; j < max_word_length; j++) cout << matrix[i][j] << ' '; 
            cout << endl; 
        } 
        // Convert the encrypted matrix to a string 

        string encrypted_sentence;  

        for (int i = 0; i < word_count; i++) { 

            for (int j = 0; j < max_word_length; j++) encrypted_sentence += matrix[i][j]; 
        } 
        cout << "Encrypted Statement: " << encrypted_sentence << endl; 
        // Decryption process 
        // Reverse column transposition: Move the first column to the last position 
        cout << "\nColumn Re-transposed Matrix:" << endl;  
        for (int i = 0; i < word_count; i++) { 
            char temp_col = matrix[i][0]; 
            for (int j = 0; j < max_word_length - 1; j++) matrix[i][j] = matrix[i][j + 1]; 
            matrix[i][max_word_length - 1] = temp_col; 
        } 
        // Print the column re-transposed matrix 
        for (int i = 0; i < word_count; i++) { 
            for (int j = 0; j < max_word_length; j++) cout << matrix[i][j] << ' '; 
            cout << endl; 
        } 
        // Reverse row transposition: Move the first row to the last position 
        for (int j = 0; j < max_word_length; j++) temp[j] = matrix[0][j]; 

        for (int i = 0; i < word_count - 1; i++) { 

            for (int j = 0; j < max_word_length; j++) matrix[i][j] = matrix[i + 1][j]; 
        } 
        for (int j = 0; j < max_word_length; j++) matrix[word_count - 1][j] = temp[j]; 
        // Print the row re-transposed matrix 
        cout << "\nRow Re-transposed Matrix:" << endl;  
        for (int i = 0; i < word_count; i++) { 
            for (int j = 0; j < max_word_length; j++) cout << matrix[i][j] << ' '; 
            cout << endl; 
        } 
        // Convert the decrypted matrix to a string 
        string decrypted_sentence;  
        for (int i = 0; i < word_count; i++) { 
            for (int j = 0; j < max_word_length; j++) { 
                if (matrix[i][j] != '*') decrypted_sentence += matrix[i][j]; 
            } 
            if (i < word_count - 1) decrypted_sentence += ' ';
        } 
        cout << "Decrypted Statement: " << decrypted_sentence << endl; 
        return 0; 
    }

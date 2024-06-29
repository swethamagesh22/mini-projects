from transformers import MarianMTModel, MarianTokenizer

def translate_text(input_text):
    model_name = "Helsinki-NLP/opus-mt-en-de"  # Pre-trained English to German model
    tokenizer = MarianTokenizer.from_pretrained(model_name)
    model = MarianMTModel.from_pretrained(model_name)
    
    input_text = [input_text]
    inputs = tokenizer(input_text, return_tensors="pt", padding=True, truncation=True)
    max_length = len(inputs["input_ids"][0]) + 50  # Adjust the desired length here
    translated = model.generate(**inputs, max_new_tokens=max_length)
    translated_text = tokenizer.batch_decode(translated, skip_special_tokens=True)
    
    return translated_text[0]

def chatbot():
    print("Welcome to the Translator AI Tool Chatbot!")
    print("Enter 'exit' to quit the chatbot.")
    
    while True:
        user_input = input("User Input in English: ")
        if user_input.lower() == "exit":
            print("Chatbot: Auf Wiedersehen! Goodbye!")
            break
        
        translated_text = translate_text(user_input)
        print("Chatbot reply in German:", translated_text)

# Start the chatbot
chatbot()

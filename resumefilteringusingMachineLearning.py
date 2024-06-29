import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.impute import SimpleImputer

# Load the dataset
data = pd.read_csv('/Users/noorehera/Documents/Applications_for_Machine_Learning_internship_edited.xlsx - Sheet1 (1).csv')

# Define the columns to use for training
columns_to_use = ['Python (out of 3)', 'Machine Learning (out of 3)', 'Natural Language Processing (NLP) (out of 3)',
                  'Deep Learning (out of 3)', 'Other skills',
                  'Are you available for 3 months, starting immediately, for a full-time work from home internship? ',
                  'Degree', 'Stream', 'Current Year Of Graduation', 'Performance_PG', 'Performance_UG',
                  'Performance_12', 'Performance_10']

# Filter the dataset based on the selected columns
filtered_data = data[columns_to_use].copy()

# Handle missing values for specific columns
columns_with_missing_values = ['Performance_PG', 'Performance_UG', 'Performance_12', 'Performance_10']
imputer = SimpleImputer(strategy='most_frequent')
filtered_data.loc[:, columns_with_missing_values] = imputer.fit_transform(filtered_data.loc[:, columns_with_missing_values])

# Drop rows with missing values
filtered_data.dropna(inplace=True)

# Preprocessing: Splitting into features and labels
X = filtered_data.drop('Other skills', axis=1)
y = filtered_data['Other skills']

# Convert categorical variables into numerical representations
X = pd.get_dummies(X)

# Splitting the dataset into training and testing sets with a fixed random seed
random_seed = 42
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=random_seed)

# Model training using Random Forest Classifier
model = RandomForestClassifier(random_state=random_seed)
model.fit(X_train, y_train)

# Find the best intern
best_intern_index = model.predict(X_test).argmax()
best_intern_prediction = y_test.iloc[best_intern_index]

print("The best intern in the dataset is predicted to be:")
print(best_intern_prediction)
import pandas as pd
file_path='passwords.xlsx'
df=pd.read_excel(file_path)
def get_pass(input_hash):
    if len(input_hash)==32:
        row=df[df['MD5#']==input_hash]
        if not row.empty:
            return row.iloc[0]['Password']
    elif len(input_hash)==64:
        row=df[df['SHA256']==input_hash]
        if not row.empty:
            return row.iloc[0]['Password']
    elif len(input_hash)==40:
        row=df[df['BLOWFISH']==input_hash]
        if not row.empty:
            return row.iloc[0]['Password']
    return "Hash not found."
input_hash=input("enter hash:")
password=get_pass(input_hash)
print("The password is:",password)

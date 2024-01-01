import hashlib

def calculate_sha1(file_path):
    sha1 = hashlib.sha1()
    with open(file_path, 'rb') as file:
        while chunk := file.read(8192):
            sha1.update(chunk)
    return sha1.hexdigest()

file_path1 = 'shattered-1.pdf'
sha1_hash1 = calculate_sha1(file_path1)
print(f"The SHA-1 hash of shattered-1: {sha1_hash1}")

file_path2 = 'shattered-2.pdf'
sha1_hash2 = calculate_sha1(file_path2)
print(f"The SHA-1 hash of shattered-2: {sha1_hash2}")


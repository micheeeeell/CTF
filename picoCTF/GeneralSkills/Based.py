from pwn import *

def convert(enc_word, base):
    dec_word = ""
    for chr_bin in enc_word:
        dec_word += chr(int(chr_bin, base))
    return dec_word

def solve_base_2(p):
    p.readuntil("Please give the ")
    enc_word = p.readuntil(" as").decode("utf-8").split(" ")[:-1]
    log.info("enc_word: {}".format(enc_word))

    dec_word = convert(enc_word, 2)
    
    log.info("dec_word: {}".format(dec_word))
    p.sendlineafter("Input:", dec_word)

def solve_base_8(p):
    p.readuntil("Please give me the  ")
    enc_word = p.readuntil(" as").decode("utf-8").split(" ")[:-1]
    log.info("enc_word: {}".format(enc_word))

    dec_word = convert(enc_word, 8)
    
    log.info("dec_word: {}".format(dec_word))
    p.sendlineafter("Input:", dec_word)

def solve_base_16(p):
    p.readuntil("Please give me the ")
    s = p.readuntil(" as").decode("utf-8").split(" ")[0]
    enc_word = [s[i: i+2] for i in range(0, len(s), 2)]
    log.info("enc_word: {}".format(enc_word))

    dec_word = convert(enc_word, 16)
    
    log.info("dec_word: {}".format(dec_word))
    p.sendlineafter("Input:", dec_word)

def main():
    context(arch="i386", os="linux")

    p = remote("2019shell1.picoctf.com", 44303)

    solve_base_2(p)
    solve_base_8(p)
    solve_base_16(p)
    print("flag is")
    p.interactive()

if __name__ == "__main__":
    main()
set nu
syntax on
filetype plugin on
set si
set nocompatible
autocmd BufNewFile *.py exec ":call SetTitle()"
function SetTitle()
        call setline(1,"#! /usr/bin/python")
        call setline(2,"# -*- coding:utf-8 -*-")
        call setline(3,"")
endfunction
autocmd BufNewFile * normal G


set mouse=v
set pastetoggle=<F9>

set tabstop=8

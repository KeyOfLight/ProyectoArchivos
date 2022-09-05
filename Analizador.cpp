#include "Analizador.h"


vector<string> Analizador::split_txt(string text){ // Split para separar tipo de comando y parametros
    stringstream text_to_split(text);
    string segment;
    vector<string> splited;

    while(std::getline(text_to_split, segment, ' ')){
       splited.push_back(segment);
    }
    return splited;
}

string Analizador::replace_txt(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

void Analizador::analizar(string entrada){
    string entradacmd = entrada;
    transform(entradacmd.begin(), entradacmd.end(), entradacmd.begin(), ::tolower);
    vector<string> cmdentrada = split_txt(entradacmd);
    vector<string> parametros;
    string comando = "";
    for(int i = 0; i< cmdentrada.size(); i++){
        if(i == 0){
            comando = cmdentrada.at(i);
        }else{
            parametros.push_back(cmdentrada.at(i));
        }
    }
    identificarParametros(comando, parametros);
}

void Analizador::identificarParametros(string comando, vector<string> parametros){
    string param = "";

    if(comando == "mkdisk"){
        cmd.param.Comando = "mkdisk";
        for(int i=0; i<parametros.size(); i++){
            param = parametros.at(i);
            if(param.find("-s->") == 0){
                param = replace_txt(param, "-s->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Tamano = param;
            } else if(param.find("-f->") == 0){
                param = replace_txt(param, "-f->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.FitType = param;

            }else if(param.find("-u->") == 0){
                param = replace_txt(param, "-u->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Dimensional = param;
            }else if(param.find("-path->") == 0){
                param = replace_txt(param, "-path->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Direccion = param;
            }
        }
        // Ejecucion de metodo
        cmd.identificacionCMD(cmd.param);

    }else if(comando == "fdisk"){ ///TERMINAR EN LOS COMANDOS
        cmd.param.Comando = "fdisk";
        for(int i=0; i<parametros.size(); i++){
            param = parametros.at(i);
            if(param.find("-s->") == 0){
                param = replace_txt(param, "-s->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Tamano = param;
            } else if(param.find("-u->") == 0){
                param = replace_txt(param, "-u->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Dimensional = param;
            }else if(param.find("-t->") == 0){
                param = replace_txt(param, "-t->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.PartType = param;
            }else if(param.find("-f->") == 0){
                param = replace_txt(param, "-f->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.FitType = param;
            }else if(param.find("-add->") == 0){
                param = replace_txt(param, "-add->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Add = param;
            }else if(param.find("-delete->") == 0){
                param = replace_txt(param, "-delete->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Delete = param;
            } else if(param.find("-path->") == 0){
                param = replace_txt(param, "-path->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Direccion = param;
            } else if(param.find("-name->") == 0){ 
                param = replace_txt(param, "-name->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Nombre = param;
            }
        }
        cmd.identificacionCMD(cmd.param);
    }else if (comando == "mount"){ //HACER EN LOS COMANDOS
        cmd.param.Comando = "mount";
        for(int i=0; i<parametros.size(); i++){
            param = parametros.at(i);
            if(param.find("-path->") == 0){
                param = replace_txt(param, "-path->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Direccion = param;
            }else if(param.find("-name->") == 0){ 
                param = replace_txt(param, "-name->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Nombre = param;
            }
        }
        cmd.identificacionCMD(cmd.param);
    }else if (comando == "unmount"){ //HACER EN LOS COMANDOS
        cmd.param.Comando = "unmount";
        for(int i=0; i<parametros.size(); i++){
            param = parametros.at(i);
            if(param.find("-path->") == 0){
                param = replace_txt(param, "-path->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Direccion = param;
            }else if(param.find("-name->") == 0){ 
                param = replace_txt(param, "-name->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Nombre = param;
            }
        }
        cmd.identificacionCMD(cmd.param);
    }else if (comando == "mkfs"){ //HACER EN LOS COMANDOS
        cmd.param.Comando = "mkfs";
        for(int i=0; i<parametros.size(); i++){
            param = parametros.at(i);
            if(param.find("-id->") == 0){
                param = replace_txt(param, "-id->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Id = param;
            }else if(param.find("-type->") == 0){ 
                param = replace_txt(param, "-type->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Tamano = param;
            }else if(param.find("-fs->") == 0){ 
                param = replace_txt(param, "-fs->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.FitType = param;
            }
        }
        cmd.identificacionCMD(cmd.param);
    }else if (comando == "exec"){
        cmd.param.Comando = "execut";
        for(int i=0; i<parametros.size(); i++){
            param = parametros.at(i);
            if(param.find("-path->") == 0){
                param = replace_txt(param, "-path->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Direccion = param;
            }
        }
        cmd.identificacionCMD(cmd.param);
    }else if(comando == "vertodo"){
        cmd.param.Comando = "vertodo";
        cmd.identificacionCMD(cmd.param);   
    } else if(comando == "rmdisk"){
        cmd.param.Comando = "rmdisk";
        for(int i=0; i<parametros.size(); i++){
            param = parametros.at(i);
            if(param.find("-path->") == 0){
                param = replace_txt(param, "-path->", "");
                param = replace_txt(param, "\"", "");
                cmd.param.Direccion = param;
            }
        }
        cmd.identificacionCMD(cmd.param);
    }
}
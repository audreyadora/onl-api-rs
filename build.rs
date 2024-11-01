use std::env;
use std::path::PathBuf;

// util for cwd
fn get_current_working_dir() -> String {
    let res = env::current_dir();
    match res {
        Ok(path) => path.into_os_string().into_string().unwrap(),
        Err(_) => "FAILED".to_string()
    }
}

fn main() {
    // carg include folder
    let header_include_path: String = "-I".to_owned() + &get_current_working_dir() + "/include";
    // bindgen output folder
    let bindings_output_path: String = get_current_working_dir().to_owned() + "/bindings";

    // bind wrapper for onl headers
    let bindings = bindgen::Builder::default()
        //onlp wrapper
        .header("wrapper.h").clang_arg(header_include_path)
        .generate()
        .expect("Unable to generate bindings");

    // write the bindings to the bindings/onl_api.rs file.
    let out_path = PathBuf::from(bindings_output_path);
    bindings
        .write_to_file(out_path.join("onl_api.rs"))
        .expect("Couldn't write bindings!");
}

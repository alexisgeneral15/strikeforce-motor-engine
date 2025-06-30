# tools/assets/pipeline/texture_processor.py
def process_texture(input_path, output_path, platform):
    img = load_image(input_path)
    
    # Optimizaciones específicas por plataforma
    if platform == "mobile":
        img = resize_to_power_of_two(img)
        img = compress_astc(img)
    elif platform == "desktop":
        img = compress_bc7(img)
    
    # Generación de mipmaps
    img.generate_mipmaps()
    
    # Guardado con metadatos
    save_texture(img, output_path, {
        'original_size': img.original_size,
        'compression': img.compression_type,
        'mipmaps': img.mipmap_count
    })
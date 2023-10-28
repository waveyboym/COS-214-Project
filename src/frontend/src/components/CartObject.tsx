type CartObjectProps = {
    id: number;
    name: string;
    price: number;
    img: string;
    description: string;
    handleRemoveItem: (id: number) => void;
}

const CartObject = (props: CartObjectProps) => {
    return (
        <div className="col-sm-6 col-lg-4 all">
            <div className="box">
            <div>
                <div className="img-box">
                <img src={props.img} alt="" />
                </div>
                <div className="detail-box">
                <h5>{props.name}</h5>
                <p>{props.description}</p>
                <div className="options">
                    <h6>R{props.price}.00</h6>
                    <button className="btn my-2 my-sm-0 btn-warning" onClick={() => props.handleRemoveItem(props.id)}>Remove</button>
                </div>
                </div>
            </div>
            </div>
        </div>
    )
}

export default CartObject
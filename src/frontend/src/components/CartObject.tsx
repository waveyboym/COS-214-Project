type CartObjectProps = {
    id: number;
    name: string;
    price: number;
    img: string;
    description: string;
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
                <h6>{props.price}</h6>
            </div>
            </div>
        </div>
        </div>
    </div>
    )
}

export default CartObject